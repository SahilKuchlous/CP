#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	int v[n];
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	int b[n];
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	map< pair<int, int>, int > ranges;
	for (int i=0; i<n-1; i++) {
		if (b[i] <= k) {
			for (int j=i+1; j<n; j++) {
				if (b[j]-k == b[i] && v[i]+v[j] > 0) {
					ranges[{i, j}] = v[i]+v[j];
				}
			}
		}
	}
	int dp[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			dp[i][j] = 0;
		}
	}
	for (int k=1; k<n; k++) {
		for (int i=0; i<n-k; i++) {
			dp[i][i+k] = 0;
			for (int j=i+1; j<i+k; j++) {
				dp[i][i+k] = max(dp[i][i+k], dp[i][j]+dp[j][i+k]);
			}
			if (ranges.find(make_pair(i, i+k)) != ranges.end()) {
				dp[i][i+k] = max(dp[i][i+k], dp[i+1][i+k-1]+ranges[make_pair(i, i+k)]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
}