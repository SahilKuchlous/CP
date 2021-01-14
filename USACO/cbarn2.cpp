#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cbarn2.in");
ofstream fout("cbarn2.out");
int main () {
	int n, k;
	fin >> n >> k;
	int cows_in[n];
	for (int i=0; i<n; i++) {
		fin >> cows_in[i];
	}
	int start = 0;
	long long score = 0;
	long long ms = 1e10;
	for (int i=0; i<n; i++) {
		score = 0;
		for (int j=0; j<n; j++) {
			score += j*cows_in[(i+j)%n];
		}
		if (score < ms) {
			ms = score;
			start = i;
		}
	}
	int cows[n];
	/*
	for (int i=0; i<n; i++) {
		cows[i] = cows_in[(start+i)%n];
		cout << cows[i] << " ";
	}
	cout << endl;
	*/
	long long dp[n][k+1];
	for (int i=1; i<=k; i++) {
		dp[0][i] = 0;
	}
	for (int i=1; i<n; i++) {
		dp[i][1] = 1e14;
	}
	for (int i=1; i<n; i++) {
		score = 0;
		for (int j=2; j<=k; j++) {
			dp[i][j] = dp[i-1][j-1];
		}
		score = 0;
		for (int j=i-2; j>=0; j--) {
			score += score + cows[j+1];
			for (int l=2; l<=k; l++) {
				dp[i][l] = min(dp[i][l], dp[j][l-1]+score);
			}
		}
	}
	/*
	for (int i=0; i<n; i++) {
		for (int j=1; j<=k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	score = 0;
	long long o = dp[n-1][k];
	for (int i=n-2; i>=0; i--) {
		score += score+cows[i+1];
		o = min(o, dp[i][k]+score);
	}
	fout << o << endl;
}