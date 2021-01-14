#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[100100];
vector<int> inc[100100];
bool vis[100100];
vector<int> ord;
void topo (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		topo(i);
	}
	ord.push_back(x);
}
int dp[100100];
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		inc[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) topo(i);
	}
	reverse(ord.begin(), ord.end());
	for (auto &i: ord) {
		for (auto &j: inc[i]) {
			dp[i] = max(dp[i], dp[j]+1);
		}
		o = max(o, dp[i]);
	}
	cout << o << endl;
}