#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("mootube.in");
ofstream fout("mootube.out");
int n, q;
map< int, vector< pair<int, int> > > adj;
int k;
int dfs (int v, int p) {
	int o = 1;
	for (auto i: adj[v]) {
		if (i.first != p && i.second >= k) {
			o += dfs(i.first, v);
		}
	}
	return o;
}
int main () {
	fin >> n >> q;
	int a, b, c;
	for (int i=0; i<n-1; i++) {
		fin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int v;
	for (int i=0; i<q; i++) {
		fin >> k >> v;
		fout << dfs(v, -1)-1 << endl;
	}
}