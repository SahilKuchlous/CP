#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 405
int n;
int a[MAXN];
vector<int> pos[3];
int dp[MAXN][MAXN][MAXN][3];
int o = 1e8;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	char ai;
	for (int i=1; i<=n; i++) {
		cin >> ai;
		if (ai == 'R') a[i] = 0;
		if (ai == 'G') a[i] = 1;
		if (ai == 'Y') a[i] = 2;
		pos[a[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=i; j++) {
			for (int k=0; k<=i; k++) {
				dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = 1e8;
			}
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=i/2+1; j++) {
			for (int k=0; k<=i/2+1; k++) {
				int l = i-j-k;
				if (j+k > i || j > pos[0].size() || k > pos[1].size() || l > pos[2].size()) continue;
				int score, cur;
				if (j > 0) {
					score = min(dp[i-1][j-1][k][1], dp[i-1][j-1][k][2]);
					cur = pos[0][j-1];
					cur += max(0l, k-(lower_bound(pos[1].begin(), pos[1].end(), pos[0][j-1])-pos[1].begin()));
					cur += max(0l, l-(lower_bound(pos[2].begin(), pos[2].end(), pos[0][j-1])-pos[2].begin()));
					score += abs(i-cur);
					dp[i][j][k][0] = min(dp[i][j][k][0], score);
				}
				if (k > 0) {
					score = min(dp[i-1][j][k-1][0], dp[i-1][j][k-1][2]);
					cur = pos[1][k-1];
					cur += max(0l, j-(lower_bound(pos[0].begin(), pos[0].end(), pos[1][k-1])-pos[0].begin()));
					cur += max(0l, l-(lower_bound(pos[2].begin(), pos[2].end(), pos[1][k-1])-pos[2].begin()));
					score += abs(i-cur);
					dp[i][j][k][1] = min(dp[i][j][k][1], score);
				}
				if (l > 0) {
					score = min(dp[i-1][j][k][0], dp[i-1][j][k][1]);
					cur = pos[2][l-1];
					cur += max(0l, j-(lower_bound(pos[0].begin(), pos[0].end(), pos[2][l-1])-pos[0].begin()));
					cur += max(0l, k-(lower_bound(pos[1].begin(), pos[1].end(), pos[2][l-1])-pos[1].begin()));
					score += abs(i-cur);
					dp[i][j][k][2] = min(dp[i][j][k][2], score);
				}
			}
		}
	}
	for (int j=0; j<=n; j++) {
		for (int k=0; k<=n; k++) {
			for (int e=0; e<3; e++) {
				o = min(o, dp[n][j][k][e]);
			}
		}
	}
	if (o == 1e8) {
		cout << -1 << endl;
	} else {
		cout << o << endl;
	}
}