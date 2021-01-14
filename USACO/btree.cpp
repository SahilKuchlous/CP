#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("btree.in");
ofstream fout("btree.out");
int n;
int val[50000];
set<int> adj[50000];
pair<int, int> up[50000];
pair<int, int> down[50000];
int o = 0;
void dfs1 (int x, int p) {
	if (x != p && adj[x].size() == 1) {
		down[x] = make_pair(max(0, val[x]), min(0, val[x]));
		return;
	}
	down[x] = make_pair(0, 0);
	for (auto i: adj[x]) {
		if (i != p) {
			dfs1(i, x);
			down[x].first = max(down[x].first, down[i].first);
			down[x].second = min(down[x].second, down[i].second);
		}
	}
	down[x].first = max(0, down[x].first+val[x]);
	down[x].second = min(0, down[x].second+val[x]);
}
void dfs2 (int x, int p) {
	if (x == p) {
		up[x] = down[x];
	} else {
		up[x].first = max(0, up[x].first+val[x]);
		up[x].second = min(0, up[x].second+val[x]);
	}
	pair<int, int> h1, h2, l1, l2;
	if (x == 0) {
		h1 = h2 = l1 = l2 = make_pair(0, 0);
	} else {
		h1 = h2 = make_pair(up[x].first, p);
		l1 = l2 = make_pair(up[x].second, p);
	}
	for (auto i: adj[x]) {
		if (i != p) {
			if (h1.first < down[i].first+val[x]) {
				h2 = h1;
				h1 = make_pair(down[i].first+val[x], i);
			} else if (h2.first < down[i].first+val[x]) {
				h2 = make_pair(down[i].first+val[x], i);
			}
			if (l1.first > down[i].second+val[x]) {
				l2 = l1;
				l1 = make_pair(down[i].second+val[x], i);
			} else if (l2.first > down[i].second+val[x]) {
				l2 = make_pair(down[i].second+val[x], i);
			}
		}
	}
	for (auto i: adj[x]) {
		if (i != p) {
			if (h1.second != i) {
				up[i].first = h1.first;
			} else {
				up[i].first = h2.first;
			}
			if (l1.second != i) {
				up[i].second = l1.first;
			} else {
				up[i].second = l2.first;
			}
		}
	}
	for (auto i: adj[x]) {
		if (i != p) {
			o = max(o, min(up[x].first, -down[i].second));
			o = max(o, min(-up[x].second, down[i].first));
			dfs2(i, x);
		}
	}
}
int main () {
	fin >> n;
	int ei;
	for (int i=1; i<n; i++) {
		fin >> ei;
		ei--;
		adj[i].insert(ei);
		adj[ei].insert(i);
	}
	char ci;
	for (int i=0; i<n; i++) {
		fin >> ci;
		if (ci == '(') {
			val[i] = 1;
		} else {
			val[i] = -1;
		}
	}
	dfs1(0, 0);
	dfs2(0, 0);
	fout << o << endl;
}