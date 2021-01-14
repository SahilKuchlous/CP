#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
ifstream fin("timeline.in");
ofstream fout("timeline.out");
int n, m, c;
int start[100100];
set< pair<int, int> > inc[100100];
set< pair<int, int> > out[100100];
vector<int> topo;
bool vis[100100];
void dfs (int x) {
	vis[x] = true;
	for (auto i: out[x]) {
		if (!vis[i.first]) {
			dfs(i.first);
		}
	}
	topo.push_back(x);
}
int main () {
	fin >> n >> m >> c;
	for (int i=1; i<=n; i++) {
		fin >> start[i];
	}
	int ai, bi, ci;
	for (int i=0; i<c; i++) {
		fin >> ai >> bi >> ci;
		inc[bi].insert(make_pair(ai, ci));
		out[ai].insert(make_pair(bi, ci));
	}
	for (int i=1; i<=n; i++) {
		vis[i] = false;
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i] && inc[i].size() == 0) {
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	int dp[n+1];
	for (auto i: topo) {
		dp[i] = start[i];
		for (auto j: inc[i]) {
			dp[i] = max(dp[i], dp[j.first]+j.second);
		}
	}
	for (int i=1; i<=n; i++) {
		fout << dp[i] << endl;
	}
}