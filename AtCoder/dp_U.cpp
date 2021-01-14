#include <iostream>
using namespace std;
int n;
long long score[16][16];
long long dp[1<<16];
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> score[i][j];
		}
	}
	for (int i=0; i<(1<<n); i++) {
		for (int j=0; j<n; j++) {
			if ((i & (1<<j)) == 0) continue;
			for (int k=j+1; k<n; k++) {
				if ((i & (1<<k)) == 0) continue;
				dp[i] += score[j][k]; 
			}
		}
	}
	for (int i=0; i<(1<<n); i++) {
		for (int j=i; j>0; j=i&(j-1)) {
			dp[i] = max(dp[i], dp[j]+dp[i^j]);
		}
	}
	cout << dp[(1<<n)-1] << endl;
}