#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int n, m;
vector<int> adj[200100];
vector<int> rev[200100];
vector<int> ord;
bool vis[200100];
int col[200100];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		rev[i].clear();
		vis[i] = false;
	}
	ord.clear();
}
void dfs (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs(i);
	}
	ord.push_back(x);
}
int main () {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		reset();
		int ai, bi;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			rev[bi].push_back(ai);
		}
		for (int i=0; i<n; i++) {
			if (!vis[i]) dfs(i);
		}
		reverse(ord.begin(), ord.end());
		int cnt = 0;
		for (int i=0; i<n; i++) {
			bool f1 = false, f2 = false, f3 = false;
			for (auto j: rev[ord[i]]) {
				if (col[j] == 1) f1 = true;
				if (col[j] == 2) f2 = true;
				if (col[j] == 3) f3 = true;
			}
			if (!f1 && !f2) {
				col[ord[i]] = 1;
			} else if (f1 && !f2) {
				col[ord[i]] = 2;
			} else {
				col[ord[i]] = 3;
				cnt++;
			}
		}
		cout << cnt << endl;
		for (int i=0; i<n; i++) {
			if (col[i] == 3) cout << i+1 << " ";
		}
		cout << endl;
	}
}