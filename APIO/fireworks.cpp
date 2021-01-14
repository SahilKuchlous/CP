#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
vector< pair<int, int> > adj[310];
long long dp[310][310];
void dfs (int x) {
	if (adj[x].size() == 0) {
		dp[x][0] = 0;
		for (int i=1; i<=300; i++) {
			dp[x][i] = 1e16;
		}
		return;
	}
	for (auto i: adj[x]) {
		dfs(i.first);
	}
	for (int i=0; i<=300; i++) {
		for (auto j: adj[x]) {
			long long best = 1e16;
			for (int k=0; k<=i; k++) {
				best = min(best, dp[j.first][k]+abs(i-k-j.second));
			}
			dp[x][i] += best;
		}
	}
}
int main () {
	cin >> n >> m;
	if (n == 1) {
		int a[m];
		int x;
		for (int i=0; i<m; i++) {
			cin >> x >> a[i];
		}
		long long o = 1e16;
		for (int i=0; i<m; i++) {
			long long cur = 0;
			for (int j=0; j<m; j++) {
				cur += abs(a[i]-a[j]);
			}
			o = min(o, cur);
		}
		cout << o << endl;
		return 0;
	}
	int pi, wi;
	for (int i=2; i<=n+m; i++) {
		cin >> pi >> wi;
		adj[pi].push_back({i, wi});
	}
	dfs(1);
	long long o = 1e16;
	for (int i=0; i<=300; i++) {
		o = min(o, dp[1][i]);
	}
	cout << o << endl;
}