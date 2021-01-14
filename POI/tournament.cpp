#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int n;
vector<int> adj[100100], inc[100100];
vector<int> topo;
bool vis[100100];
void dfs1 (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs1(i);
	}
	topo.push_back(x);
}
int cnt = 0;
bool win[100100];
int id[100100];
void dfs2 (int x) {
	vis[x] = true;
	id[x] = cnt;
	for (auto i: inc[x]) {
		if (!vis[i]) {
			dfs2(i);
		} else if (id[i] != cnt) {
			win[cnt] = false;
		}
	}
}
set<int> o;
queue<int> bfs;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai;
		for (int j=0; j<ai; j++) {
			cin >> bi;
			bi--;
			adj[i].push_back(bi);
			inc[bi].push_back(i);
		}
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) dfs1(i);
	}
	reverse(topo.begin(), topo.end());
	for (int i=0; i<n; i++) vis[i] = false;
	for (auto i: topo) {
		if (!vis[i]) {
			win[cnt] = true;
			dfs2(i);
			cnt++;
		}
	}
	for (int i=0; i<n; i++) vis[i] = false;
	for (int i=0; i<n; i++) {
		if (win[id[i]]) {
			o.insert(i);
			bfs.push(i);
			vis[i] = true;
		}
	}
	while (bfs.size()) {
		int cur = bfs.front();
		bfs.pop();
		int c = 0;
		for (auto i: inc[cur]) {
			if (o.find(i) != o.end()) c++;
		}
		if (c != o.size()) o.insert(cur);
		for (auto i: adj[cur]) {
			if (!vis[i]) {
				bfs.push(i);
				vis[i] = true;
			}
		}
	}
	for (int k=0; k<2; k++) for (int i=0; i<n; i++) {
		int c = 0;
		for (auto j: inc[i]) {
			if (o.find(j) != o.end()) c++;
		}
		if (c != o.size()) o.insert(i);
	}
	cout << o.size() << " ";
	for (auto i: o) cout << i+1 << " ";
	cout << endl;
}