#include <iostream>
using namespace std;
int n, m;
int seq[100100];
int cnt[20][20];
int dp[2000000];
int main () {
	cin >> n >> m;
	char inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		seq[i] = inp-'a';
	}
	for (int i=0; i<n-1; i++) {
		cnt[seq[i]][seq[i+1]]++;
		cnt[seq[i+1]][seq[i]]++;
	}
	int score;
	for (int i=1; i<(1<<m); i++) {
		dp[i] = 1e8;
		int on = 0;
		for (int j=0; j<m; j++) {
			if (i & (1<<j)) on++;
		}
		for (int j=0; j<m; j++) {
			if ((i & (1<<j)) == 0) continue;
			score = dp[i-(1<<j)];
			for (int k=0; k<m; k++) {
				if (j == k) continue;
				if (i & (1<<k)) {
					score += cnt[j][k]*on;
				} else {
					score -= cnt[j][k]*on;
				}
			}
			dp[i] = min(dp[i], score);
		}
	}
	cout << dp[(1<<m)-1] << endl;
}