#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("hps.in");
ofstream fout("hps.out");
int main () {
	int n, s;
	fin >> n >> s;
	int moves[n];
	char inp;
	for (int i=0; i<n; i++) {
		fin >> inp;
		if (inp == 'H') {
			moves[i] = 0;
		} else if (inp == 'P') {
			moves[i] = 1;
		} else if (inp == 'S') {
			moves[i] = 2;
		}
	}
	int dp[n][s+1][3];
	int best[n][s+1];
	for (int i=0; i<=s; i++) {
		for (int j=0; j<3; j++) {
			if (moves[0] == j) {
				dp[0][i][j] = 1;
			} else {
				dp[0][i][j] = 0;
			}
		}
		best[0][i] = 1;
	}
	for (int i=1; i<n; i++) {
		for (int j=0; j<3; j++) {
			if (moves[i] == j) {
				dp[i][0][j] = dp[i-1][0][j]+1;
			} else {
				dp[i][0][j] = dp[i-1][0][j];
			}
		}
		best[i][0] = max(dp[i][0][0], max(dp[i][0][1], dp[i][0][2]));
		for (int j=1; j<=s; j++) {
			for (int k=0; k<3; k++) {
				if (moves[i] == k) {
					// cout << best[i-1][j-1] << endl;
					dp[i][j][k] = max(dp[i-1][j][k], best[i-1][j-1])+1;
				} else {
					dp[i][j][k] = dp[i-1][j][k];
				}
			}
			best[i][j] = max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2]));
		}
		// cout << dp[i][s][0] << " " << dp[i][s][1] << " " << dp[i][s][2] << endl;
	}
	fout << best[n-1][s] << endl;
}