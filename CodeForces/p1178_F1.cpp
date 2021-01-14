#include <iostream>
using namespace std;
#define MOD 998244353
int n, m;
int col[510];
long long dp[510][510];
bool vis[510][510];
long long calc (int s, int e) {
	if (s == e) return 1;
	if (vis[s][e]) return dp[s][e];
	vis[s][e] = true;
	int val = 1e9, pos = -1;
	for (int i=s; i<e; i++) {
		if (col[i] < val) {
			val = col[i];
			pos = i;
		}
	}
	long long v1 = 0;
	for (int ns=pos; ns>=s; ns--) {
		v1 += calc(s, ns)*calc(ns, pos)%MOD;
		v1 %= MOD;
	}
	long long v2 = 0;
	for (int ne=pos+1; ne<=e; ne++) {
		v2 += calc(pos+1, ne)*calc(ne, e)%MOD;
		v2 %= MOD;
	}
	dp[s][e] = (v1*v2)%MOD;
	return dp[s][e];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> col[i];
	}
	cout << calc(0, m) << endl;
}