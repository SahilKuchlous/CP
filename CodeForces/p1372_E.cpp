#include <iostream>
using namespace std;
#define MAXN 105
int n, m;
int lft[MAXN][MAXN];
int rt[MAXN][MAXN];
int dp[MAXN][MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int cnt;
		cin >> cnt;
		int li, ri;
		while (cnt--) {
			cin >> li >> ri;
			li--; ri--;
			for (int j=li; j<=ri; j++) {
				lft[j][i] = li;
				rt[j][i] = ri;
			}
		}
	}
	for (int r=0; r<m; r++) {
		for (int l=r; l>=0; l--) {
			for (int m=l; m<=r; m++) {
				int cnt = 0;
				for (int i=0; i<n; i++) {
					if (lft[m][i] >= l && rt[m][i] <= r) cnt++;
				}
				int score = cnt*cnt;
				if (m > l) score += dp[l][m-1];
				if (m < r) score += dp[m+1][r];
				dp[l][r] = max(dp[l][r], score);
			}
		}
	}
	cout << dp[0][m-1] << endl;
}