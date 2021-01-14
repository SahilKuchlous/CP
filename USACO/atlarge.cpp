#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("atlarge.in");
ofstream fout("atlarge.out");
int n, k;
map< int, vector<int> > adj;
int min_dist[100100];
void dfs1 (int v, int p) {
	if (adj[v].size() == 1) {
		min_dist[v] = 0;
		return; 
	}
	int ans = 1000000;
	for (auto i: adj[v]) {
		if (i != p) {
			dfs1(i, v);
			ans = min(ans, min_dist[i]+1);
		}
	}
	min_dist[v] = ans;
}
int dfs2 (int v, int p, int d) {
	if (d >= min_dist[v]) {
		return 1;
	}
	int ans = 0;
	for (auto i: adj[v]) {
		if (i != p) {
			ans += dfs2(i, v, d+1);
		}
	}
	return ans;
}
int main () {
	fin >> n >> k;
	int a, b;
	for (int i=0; i<n-1; i++) {
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(k, -1);
	int o = dfs2(k, -1, 0);
	fout << o << endl;
}