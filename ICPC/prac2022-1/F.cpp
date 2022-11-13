#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAXN 100005
int n;
int c[MAXN];
int ttl[MAXN];
vector< pair<int, int> > adj[MAXN];
map<int, int> subtree[MAXN];
int ptr[MAXN];
long long o[MAXN];

void dfs (int x, int p, int e) {
	if (adj[x].size() == 1 && e != -1) {
		ptr[x] = x;
		subtree[x][c[x]] = 1;
		o[e] = ttl[c[x]]-1;
		return;
	}
	int max_sz = -1, max_id = -1;
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		dfs(i.first, x, i.second);
		o[e] += o[i.second];
		if ((int)subtree[ptr[i.first]].size() > max_sz) {
			max_sz = subtree[ptr[i.first]].size();
			max_id = i.first;
		}
	}
	if (e == -1) return;
	ptr[x] = ptr[max_id];
	if (subtree[ptr[x]].find(c[x]) == subtree[ptr[x]].end()) {
		subtree[ptr[x]][c[x]] = 1;
	} else {
		o[e] -= subtree[ptr[x]][c[x]];
		subtree[ptr[x]][c[x]]++;
		o[e] += (ttl[c[x]]-subtree[ptr[x]][c[x]])*subtree[ptr[x]][c[x]];
	}
	for (auto i: adj[x]) {
		if (i.first == p || i.first == max_id) continue;
		for (auto j: subtree[ptr[i.first]]) {
			if (subtree[ptr[x]].find(j.first) != subtree[ptr[x]].end()) {
				o[e] -= subtree[ptr[x]][j.first]*j.second;
				subtree[ptr[x]][j.first] += j.second;
			} else {
				subtree[ptr[x]][j.first] = j.second;
			}
		}
	}
	for (auto i: subtree[ptr[x]]) {
		cout << x << " " << i.first << " " << i.second << endl;
	}
	cout << endl;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> c[i];
		c[i]--;
		ttl[c[i]]++;
	}
	int u, v;
	for (int i=0; i<n-1; i++) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(make_pair(v, i));
		adj[v].push_back(make_pair(u, i));
	}
	dfs(0, 0, -1);
	for (int i=0; i<n-1; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}