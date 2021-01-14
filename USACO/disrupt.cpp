#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream fin("disrupt.in");
ofstream fout("disrupt.out");
vector< pair<int, int> > adj[100100];
set< pair<int, int> > opts[100100];
int oid[100100];
int ans[100100];
void dfs (int x, int p, int e) {
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs(i.first, x, i.second);
			if (opts[oid[i.first]].size() > opts[oid[x]].size()) {
				for (auto j: opts[oid[x]]) {
					if (opts[oid[i.first]].find(j) == opts[oid[i.first]].end()) {
						opts[oid[i.first]].insert(j);
					} else {
						opts[oid[i.first]].erase(j);
					}
				}
				oid[x] = oid[i.first];
			} else {
				for (auto j: opts[oid[i.first]]) {
					if (opts[oid[x]].find(j) == opts[oid[x]].end()) {
						opts[oid[x]].insert(j);
					} else {
						opts[oid[x]].erase(j);
					}
				}
			}
		}
	}
	if (e != -1) {
		if (opts[oid[x]].size() == 0) {
			ans[e] = -1;
		} else {
			ans[e] = opts[oid[x]].begin()->first;
		}
	}
}
int main () {
	int n, m;
	fin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
	}
	for (int i=0; i<m; i++) {
		fin >> ai >> bi >> ci;
		ai--;
		bi--;
		opts[ai].insert(make_pair(ci, i));
		opts[bi].insert(make_pair(ci, i));
	}
	for (int i=0; i<n; i++) {
		oid[i] = i;
	}
	dfs(0, -1, -1);
	for (int i=0; i<n-1; i++) {
		fout << ans[i] << endl;
	}
}