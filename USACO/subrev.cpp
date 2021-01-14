#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subrev.in");
ofstream fout("subrev.out");
int dp[60][60][60][60];
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<=50; k++) {
				for (int l=0; l<=50; l++) {
					if (l < k) {
						dp[i][j][k][l] = -1e8;
						continue;
					}
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	for (int len=0; len<n; len++) {
		for (int start=0; start+len<n; start++) {
			for (int pre=0; pre<=50; pre++) {
				for (int suf=pre; suf<=50; suf++) {
					if (len == 0) {
						if (pre <= a[start] && suf >= a[start]) {
							dp[start][start][pre][suf] = 1;
						}
						continue;
					}
					dp[start][start+len][pre][suf] = max(dp[start+1][start+len-1][pre][suf], max(dp[start+1][start+len][pre][suf], dp[start][start+len-1][pre][suf]));
					if (pre <= a[start]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start+1][start+len][a[start]][suf]+1);
					if (suf >= a[start+len]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start][start+len-1][pre][a[start+len]]+1);
					if (pre <= a[start] && suf >= a[start+len] && a[start] <= a[start+len]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start+1][start+len-1][a[start]][a[start+len]]+2);
					if (pre <= a[start+len]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start+1][start+len-1][a[start+len]][suf]+1);
					if (suf >= a[start]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start+1][start+len-1][pre][a[start]]+1);
					if (pre <= a[start+len] && suf >= a[start] && a[start+len] <= a[start]) dp[start][start+len][pre][suf] = max(dp[start][start+len][pre][suf], dp[start+1][start+len-1][a[start+len]][a[start]]+2);
				}
			}
		}
	}
	fout << dp[0][n-1][0][50] << endl;
}