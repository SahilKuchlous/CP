#include <iostream>
using namespace std;
#define MOD 1000000007
long long dp[2100][2100];
bool vis[2100][2100];
long long solve (int len, int ttl) {
	if (2*len < ttl) return 0;
	if (ttl < 0) return 0;
	if (len == 1 && ttl <= 2) return 1;
	if (vis[len][ttl]) return dp[len][ttl];
	vis[len][ttl] = true;
	dp[len][ttl] = (dp[len][ttl]+solve(len-1, ttl))%MOD;
	dp[len][ttl] = (dp[len][ttl]+solve(len-1, ttl+2))%MOD;
	dp[len][ttl] = (dp[len][ttl]+solve(len-1, ttl-2))%MOD;
	if (ttl > 0) dp[len][ttl] = (dp[len][ttl]+solve(len-1, ttl))%MOD;
	if (solve(len-1, ttl) > 0 || solve(len-1, ttl+2) > 0) dp[len][ttl] = (dp[len][ttl]+1)%MOD;
	if ((ttl > 0 && solve(len-1, ttl) > 0) || solve(len-1, ttl-2) > 0) dp[len][ttl] = (dp[len][ttl]+1)%MOD;
	return dp[len][ttl];
}
int main () {
	int n;
	cin >> n;
	cout << solve(n, 0) << endl;
}