#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream fin("grass.in");
ofstream fout("grass.out");
int n, m;
vector<int> adj[100100];
vector<int> rev[100100];
bool vis[100100];
vector<int> topo;
int grp[100100];
int cnt = 0;
void dfs1 (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	topo.push_back(x);
}
void dfs2 (int x) {
	grp[x] = cnt;
	vis[x] = true;
	for (auto i: rev[x]) {
		if (!vis[i]) {
			dfs2(i);
		}
	}
}
int main () {
	fin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		rev[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	for (int i=n-1; i>=0; i--) {
		if (!vis[topo[i]]) {
			dfs2(topo[i]);
			cnt++;
		}
	}
	int size[cnt];
	for (int i=0; i<cnt; i++) {
		size[i] = 0;
	}
	set<int> adj_scc[cnt];
	set<int> rev_scc[cnt];
	for (int i=0; i<n; i++) {
		size[grp[i]]++;
		for (auto j: adj[i]) {
			if (grp[i] != grp[j]) {
				adj_scc[grp[i]].insert(grp[j]);
				rev_scc[grp[j]].insert(grp[i]);
			}
		}
	}
	int dp_fwd[cnt];
	for (int i=0; i<cnt; i++) {
		dp_fwd[i] = -1;
	}
	dp_fwd[grp[0]] = size[grp[0]];
	for (int i=grp[0]+1; i<cnt; i++) {
		for (auto j: rev_scc[i]) {
			if (dp_fwd[j] > -1) dp_fwd[i] = max(dp_fwd[i], dp_fwd[j]+size[i]);
		}
	}
	int dp_back[cnt];
	for (int i=0; i<cnt; i++) {
		dp_back[i] = -1;
	}
	dp_back[grp[0]] = 0;
	for (int i=grp[0]-1; i>=0; i--) {
		for (auto j: adj_scc[i]) {
			if (dp_back[j] > -1) dp_back[i] = max(dp_back[i], dp_back[j]+size[i]);
		}
	}
	int o = size[grp[0]];
	for (int i=0; i<cnt; i++) {
		for (auto j: adj_scc[i]) {
			if (dp_fwd[j] > -1 && dp_back[i] > -1) o = max(o, dp_fwd[j]+dp_back[i]);
		}
	}
	fout << o << endl;
}