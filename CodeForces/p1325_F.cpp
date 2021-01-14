#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
int n, m;
vector<int> adj[100100];
bool vis[100100];
int depth[100100];
stack<int> path;
bool block[100100];
vector<int> cycle;
vector<int> ind;
bool f = false;
int rt;
int d;
void dfs (int x) {
	if (f) return;
	vis[x] = true;
	depth[x] = d;
	d++;
	path.push(x);
	int min_d = 100100;
	for (auto i: adj[x]) {
		if (vis[i]) min_d = min(min_d, depth[i]);
	}
	if (depth[x]-min_d >= rt-1) {
		for (int i=0; i<=depth[x]-min_d; i++) {
			cycle.push_back(path.top());
			path.pop();
		}
		f = true;
		return;
	}
	for (auto i: adj[x]) {
		if (!vis[i]) dfs(i);
		if (f) return;
	}
	if (!block[x]) {
		ind.push_back(x);
		for (auto i: adj[x]) {
			if (depth[i] < depth[x]) block[i] = true;
		}
	}
	d--;
	path.pop();
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		vis[i] = block[i] = false;
	}
	rt = ceil(sqrt(1.0*n));
	d = 0;
	dfs(0);
	if (!f) {
		cout << 1 << endl;
		for (int i=0; i<rt; i++) cout << ind[i]+1 << " ";
		cout << endl;
	} else {
		cout << 2 << endl;
		cout << cycle.size() << endl;
		for (auto i: cycle) cout << i+1 << " ";
		cout << endl;
	}
}