#include <iostream>
#include <vector>
using namespace std;
#define MAXN 5005
#define MOD 1000000007

long long fact[MAXN];
void calc_fact () {
	fact[0] = 1;
	for (int i=1; i<MAXN; i++) {
		fact[i] = fact[i-1]*i % MOD;
	}
}

long long pow2[MAXN];
void calc_pow2 () {
	pow2[0] = 1;
	for (int i=1; i<MAXN; i++) {
		pow2[i] = pow2[i-1]*2 % MOD;
	}
}

long long nck[MAXN][MAXN];
void calc_nck () {
	for (int i=0; i<MAXN; i++) {
		nck[i][0] = 1;
	}
	for (int i=1; i<MAXN; i++) {
		for (int j=1; j<=i; j++) {
			nck[i][j] = (nck[i-1][j]+nck[i-1][j-1]) % MOD;
		}
	}
}

int n, m;
vector<int> adj[MAXN];
int c, c1, c2;
bool vis[MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		vis[i] = false;
	}
	c = c1 = c2 = 0;
}

int cnt;
void dfs (int x) {
	vis[x] = true;
	cnt++;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs(i);
	}
}

long long calc (int n) {
	return fact[n-1]*pow2[n-1]%MOD;
}

long long dp[MAXN];
void solve () {
	cin >> n >> m;
	reset();
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	if (n < 3) {
		cout << 0 << '\n';
		return;
	}
	for (int i=0; i<n; i++) {
		if (adj[i].size() > 2) {
			cout << 0 << '\n';
			return;
		}
		if (!vis[i]) {
			cnt = 0;
			dfs(i);
			if (cnt == 1) {
				c1++;
			} else if (cnt == 2) {
				c2++;
			} else {
				c++;
			}
		}
	}
	cout << c << endl;
	dp[0] = 1;
	for (int i=1; i<=c; i++) {
		for (int j=i; j>0; j--) {
			dp[j] = dp[j-1] * nck[i-1][i-j] % MOD * calc(i-j+1) % MOD;
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	calc_fact();
	calc_pow2();
	calc_nck();
	while (t--) {
		solve();
	}
}