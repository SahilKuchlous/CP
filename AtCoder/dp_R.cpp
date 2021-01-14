#include <iostream>
using namespace std;
#define MOD 1000000007
int n;
long long d;
long long dp[51][51][61];
long long cur[51], temp[51];
long long o = 0;
int main () {
	cin >> n >> d;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> dp[i][j][0];
		}
	}
	for (int k=1; k<=60; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int m=0; m<n; m++) {
					dp[i][j][k] += (dp[i][m][k-1]*dp[m][j][k-1])%MOD;
					dp[i][j][k] %= MOD;
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		cur[i] = 1;
	}
	for (int k=0; k<=60; k++) {
		if ((d&(1ll<<k)) == 0) continue;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				temp[j] += (cur[i]*dp[i][j][k])%MOD;
				temp[j] %= MOD;
			}
		}
		for (int i=0; i<n; i++) {
			cur[i] = temp[i];
			temp[i] = 0;
		}
	}
	for (int i=0; i<n; i++) {
		o += cur[i];
		o %= MOD;
	}
	cout << o << endl;
}