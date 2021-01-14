#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long dp[n][n];
	for (int i=0; i<n; i++) {
		dp[i][i] = 0;
	}
	long long s;
	for (int i=1; i<n; i++) {
		for (int j=0; j<n-i; j++) {
			dp[j][j+i] = 0;
			if (a[j] > 0 || a[j+i] < 0) {
				continue;
			}
			for (int k=j+1; k<j+i; k++) {
				if (a[k] == -a[j]) {
					for (int l=k+1; l<j+i; l++) {
						if (a[l] == -a[j+i]) {
							s = 1;
							for (int m=k+1; m<l; m++) {
								for (int o=m+1; o<l; o++) {
									s += dp[m][o];
								}
							}
							dp[j][j+i] += (s*dp[j][k]*dp[l][j+i])%1000000007;
							dp[j][j+i] = dp[j][j+i]%1000000007;
							// cout << j << " " << j+i << " " << dp[j][j+i] << " " << s << " " << dp[j][k] << " " << dp[l][j+i] << endl;
						}
					}
				}
			}
			if (a[j] == -a[j+i]) {
				s = 1;
				for (int k=j+1; k<j+i; k++) {
					for (int l=k+1; l<j+i; l++) {
						s += dp[k][l];
					}
				}
				dp[j][j+i] += s;
			}
		}
	}
	s = 1;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			/*
			if (dp[i][j] > 0) {
				cout << i << " " << j << " " << dp[i][j] << endl;
			}
			*/
			s += dp[i][j];
			s = s%1000000007;
		}
	}
	cout << s << endl;
}