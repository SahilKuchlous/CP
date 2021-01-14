#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, d;
		cin >> n >> m >> d;
		int a[n+1][m+1];
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				cin >> a[i][j];
			}
		}
		int pfx[n+1][m+1];
		for (int i=1; i<=n; i++) {
			pfx[i][0] = 0;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				pfx[i][j] = pfx[i][j-1]+a[i][j];
			}
		}
		long long dp1[n+1][m+1][d+1];
		long long dp2[n+1][m+1][d+1];
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=m; j++) {
				for (int k=0; k<=d; k++) {
					dp1[i][j][k] = -1e11;
					dp2[i][j][k] = 1e11;
				}
			}
		}
		for (int j=1; j<=m; j++) {
			dp1[0][j][0] = 0;
			dp2[0][j][0] = 0;
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				dp1[i][j][0] = max(dp1[i][j][0], dp1[i-1][j][0]+pfx[i][j]);
				dp2[i][j][0] = min(dp2[i][j][0], dp2[i-1][j][0]+pfx[i][j-1]);
				for (int k=1; k<=min(j-1, min(i-1, d)); k++) {
					dp1[i][j][k] = max(dp1[i][j][k], max(dp1[i-1][j][k], dp1[i-1][j-1][k-1])+pfx[i][j]);
					dp2[i][j][k] = min(dp2[i][j][k], min(dp2[i-1][j][k], dp2[i-1][j-1][k-1])+pfx[i][j-1]);
				}
			}
		}
		/*
		for (int i=1; i<=m; i++) {
			cout << dp1[n][i][0] << " ";
		}
		cout << endl;
		*/
		long long best_max[m+1];
		long long best_min[m+1];
		for (int j=1; j<=m; j++) {
			best_max[j] = -1e11;
			best_min[j] = 1e11;
			for (int k=0; k<=min(j-1, min(n-1, d)); k++) {
				// cout << dp1[n][j][j-i] << " ";
				best_max[j] = max(best_max[j], dp1[n][j][k]);
				best_min[j] = min(best_min[j], dp2[n][j][k]);
			}
			// cout << endl;
		}
		/*
		for (int i=1; i<=m; i++) {
			cout << best_max[i] << " ";
		}
		cout << endl;
		for (int i=1; i<=m; i++) {
			cout << best_min[i] << " ";
		}
		cout << endl;
		*/
		long long out = -1e11;
		for (int i=d+2; i<=m; i++) {
			for (int j=1; j<=i-d-1; j++) {
				out = max(out, best_max[i]-best_min[j]);
			}
		}
		cout << out << endl;
	}
}