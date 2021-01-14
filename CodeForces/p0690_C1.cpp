#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1005
int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];
void dfs (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs(i);
	}
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	if (m != n-1) {
		cout << "no" << endl;
		return 0;
	}
	dfs(0);
	for (int i=0; i<n; i++) {
		if (!vis[i]) {
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
}