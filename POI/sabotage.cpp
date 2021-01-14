#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int n, k;
vector<int> adj[500100];
double sz[500100];
double dp[500100];
double o = 0;
void dfs (int x) {
	sz[x] = 1;
	for (auto i: adj[x]) {
		dfs(i);
		sz[x] += sz[i];
	}
	if (x > 0 && sz[x] == 1) {
		dp[x] = 1;
		return;
	}
	dp[x] = 0;
	for (auto i: adj[x]) {
		dp[x] = max(dp[x], min(dp[i], sz[i]/(sz[x]-1)));
	}
	if (sz[x] > k) o = max(o, dp[x]);
}
int main () {
	cout << fixed << setprecision(10);
	cin >> n >> k;
	int ai;
	for (int i=1; i<n; i++) {
		cin >> ai;
		ai--;
		adj[ai].push_back(i);
	}
	dfs(0);
	cout << o << endl;
}