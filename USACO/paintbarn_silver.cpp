#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");
int dp[1001][1001];
int main () {
	int n, k;
	fin >> n >> k;
	int a, b, c, d;
	for (int i=0; i<n; i++) {
		fin >> a >> b >> c >> d;
		dp[a][b]++;
		dp[c][b]--;
		dp[a][d]--;
		dp[c][d]++;
	}
	int o = 0;
	for (int i=0; i<=1000; i++) {
		for (int j=0; j<=1000; j++) {
			if (i) dp[i][j] += dp[i-1][j];
			if (j) dp[i][j] += dp[i][j-1];
			if (i && j) dp[i][j] -= dp[i-1][j-1];
			if (dp[i][j]==k) o++;
		}
	}
	fout << o << endl;
}