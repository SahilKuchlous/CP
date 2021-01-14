#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1000000007;
int n;
vector<int> adj[100100];
int color[100100];
long long dp[100100][2];
int gcd (int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b%a, a, &x1, &y1);
	*x = y1 - (b/a)*x1;
	*y = x1;
	return g;
}
long long mod_inv (int b) {
	int x, y;
	int g = gcd(b, MOD, &x, &y);
	return (x%MOD + MOD) % MOD;
}
long long mod_div (int a, int b) {
	a = a%MOD;
	return (mod_inv(b)*a)%MOD;
}
void dfs (int x, int p) {
	long long black = 0;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x);
			black += dp[i][1];
		}
	}
	if (color[x] == 0) {
		dp[x][0] = 1;
		for (auto i: adj[x]) {
			if (i != p) {
				dp[x][0] *= (dp[i][0]+dp[i][1])%MOD;
				dp[x][0] %= MOD;
			}
		}
		dp[x][1] = 0;
		for (auto i: adj[x]) {
			if (i != p) {
				dp[x][1] += (dp[i][1]*mod_div(dp[x][0], dp[i][0]+dp[i][1]))%MOD;
				dp[x][1] %= MOD;
			}
		}
	} else {
		dp[x][0] = 0;
		dp[x][1] = 1;
		for (auto i: adj[x]) {
			if (i != p) {
				dp[x][1] *= (dp[i][0]+dp[i][1])%MOD;
				dp[x][1] %= MOD;
			}
		}
	}
}
int main () {
	cin >> n;
	int inp;
	for (int i=1; i<n; i++) {
		cin >> inp;
		adj[inp].push_back(i);
		adj[i].push_back(inp);
	}
	for (int i=0; i<n; i++) {
		cin >> color[i];
	}
	dfs(0, 0);
	cout << dp[0][1] << endl;
}