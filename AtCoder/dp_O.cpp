#include <iostream>
using namespace std;
#define MOD 1000000007
int n;
int adj[30];
long long dp[(1<<21)];
int main () {
	cin >> n;
	bool inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> inp;
			if (inp) adj[i] |= (1<<j);
		}
	}
	dp[0] = 1;
	for (int i=1; i<(1<<n); i++) {
		int cnt = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) cnt++;
		}
		for (int j=0; j<n; j++) {
			if (i & (1<<j) && (adj[cnt-1] & (1<<j))) {
				dp[i] = (dp[i]+dp[i-(1<<j)])%MOD;
			}
		}
	}
	cout << dp[(1<<n)-1] << endl;
}