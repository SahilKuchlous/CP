#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000005
int n, m;
int grid[3][MAXN];
int cols[MAXN];
vector<int> opts[8];
vector< vector<int> > dp;
int o = 1e8;
int main () {
	cin >> n >> m;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n > 3) {
		cout << -1 << endl;
		return 0;
	}
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			grid[i][j] = inp-'0';
		}
	}
	for (int j=0; j<m; j++) {
		for (int i=0; i<n; i++) {
			if (grid[i][j]) cols[j] |= (1<<i);
		}
	}
	for (int i=0; i<(1<<n); i++) {
		for (int j=0; j<(1<<n); j++) {
			if ((((i&1) > 0)+((i&2) > 0)+((j&1) > 0)+((j&2) > 0))%2 == 0) continue;
			if (n > 2 && (((i&2) > 0)+((i&4) > 0)+((j&2) > 0)+((j&4) > 0))%2 == 0) continue;
			opts[i].push_back(j); 
		}
	}
	dp.push_back(vector<int>(1<<n, 0));
	for (int i=1; i<=m; i++) {
		dp.push_back(vector<int>(1<<n, 1e8));
		for (int cur=0; cur<(1<<n); cur++) {
			int cost = 0;
			for (int j=0; j<n; j++) {
				if ((cur ^ cols[i-1]) & (1<<j)) cost++;
			}
			for (auto prv: opts[cur]) {
				dp[i][cur] = min(dp[i][cur], dp[i-1][prv]+cost);
			}
			if (i == m) o = min(o, dp[i][cur]);
		}
	}
	cout << o << endl;
}