#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp (const vector<int> &a, const vector<int> &b) {
	int m1 = 0, m2 = 0;
	for (int i=0; i<a.size(); i++) {
		m1 = max(m1, a[i]);
		m2 = max(m2, b[i]);
	}
	return m1 > m2;
}
int n, m;
int best[15][(1<<12)];
int dp[15][(1<<12)];
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> cols[m];
		int ai;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> ai;
				cols[j].push_back(ai);
			}
		}
		sort(cols, cols+m, comp);
		for (int i=1; i<=min(n, m); i++) {
			for (int j=0; j<(1<<n); j++) {
				best[i][j] = 0;
				for (int sft=0; sft<n; sft++) {
					int ttl = 0;
					for (int pos=0; pos<n; pos++) {
						if (j & (1<<pos)) ttl += cols[i-1][(pos+sft)%n];
					}
					best[i][j] = max(best[i][j], ttl);
				}
			}
		}
		for (int i=1; i<=min(n, m); i++) {
			for (int j=0; j<(1<<n); j++) {
				dp[i][j] = best[i][j];
				for (int k=j; k>0; k=(k-1)&j) {
					dp[i][j] = max(dp[i][j], dp[i-1][k]+best[i][j^k]);
				}
			}
		}
		cout << dp[min(n, m)][(1<<n)-1] << endl;
	}
}