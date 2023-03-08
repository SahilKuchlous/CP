#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define MAXN 200005
int n, m;
set<int> adj[MAXN];
int ptr[MAXN];
long long o;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		ptr[i] = i;
	}
	int u, v;
	for (int i=0; i<m; i++) {
		cin >> u >> v;
		u--; v--;
		if (u > v) swap(u, v);
		adj[u].insert(v);
	}
	for (int i=0; i<n; i++) {
		if (adj[ptr[i]].size() == 0) continue;
		int nxt = *adj[ptr[i]].begin();
		if (adj[ptr[i]].size() <= adj[ptr[nxt]].size()) {
			for (auto j: adj[ptr[i]]) {
				if (j == nxt || adj[ptr[nxt]].find(j) != adj[ptr[nxt]].end()) continue;
				o++;
				adj[ptr[nxt]].insert(j);
			}
		} else {
			int existing = 0;
			o += adj[ptr[i]].size()-1;
			for (auto j: adj[ptr[nxt]]) {
				if (adj[ptr[i]].find(j) == adj[ptr[i]].end()) {
					adj[ptr[i]].insert(j);
				} else {
					existing++;
				}
			}
			adj[ptr[i]].erase(nxt);
			o -= existing;
			ptr[nxt] = ptr[i];
		}
	}
	cout << o << endl;

	/*
	o = 0;
	for (int i=0; i<n; i++) {
		for (auto j: adj[i]) {
			for (auto k: adj[i]) {
				if (j == k) continue;
				if (adj[j].find(k) == adj[j].end()) {
					o++;
					adj[j].insert(k);
					adj[k].insert(j);
				}
			}
		}
		for (auto j: adj[i]) {
			adj[j].erase(i);
		}
	}
	cout << o << endl;
	*/
}