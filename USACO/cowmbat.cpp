#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("cowmbat.in");
ofstream fout("cowmbat.out");
int main () {
	int n, m, k;
	fin >> n >> m >> k;
	string s;
	fin >> s;
	int cost[m][m];
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			fin >> cost[i][j];
		}
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<m; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
				cost[k][j] = min(cost[k][j], cost[k][i]+cost[i][j]);
			}
		}
	}
	/*
	cout << endl;
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int sum[n+1][m];
	for (int i=0; i<m; i++) {
		sum[0][i] = 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<m; j++) {
			sum[i][j] = sum[i-1][j]+cost[s.at(i-1)-'a'][j];
		}
	}
	/*
	for (int i=0; i<m; i++) {
		for (int j=0; j<=n; j++) {
			cout << sum[j][i] << " ";
		}
		cout << endl;
	}
	*/
	int dp[n+1][m];
	int min_dp[n+1];
	for (int i=0; i<m; i++) {
		dp[0][i] = 0;
	}
	min_dp[0] = 0;
	for (int i=1; i<=n; i++) {
		min_dp[i] = 1e8;
		for (int j=0; j<m; j++) {
			if (i < k) {
				dp[i][j] = 1e8;
			} else {
				dp[i][j] = min(min_dp[i-k]+sum[i][j]-sum[i-k][j], dp[i-1][j]+cost[s.at(i-1)-'a'][j]);
			}
			min_dp[i] = min(min_dp[i], dp[i][j]);
		}
	}
	int o = 1e8;
	/*
	for (int i=0; i<m; i++) {
		for (int j=0; j<=n; j++) {
			cout << dp[j][i] << " ";
		}
		cout << endl;
	}
	*/
	for (int i=0; i<m; i++) {
		o = min(o, dp[n][i]);
	}
	fout << o << endl;
}