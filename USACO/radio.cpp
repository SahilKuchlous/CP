#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ifstream fin("radio.in");
ofstream fout("radio.out");
long long dist (pair<int, int> p1, pair<int, int> p2) {
	return pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2);
}
int main () {
	int n, m;
	fin >> n >> m;
	int fx, fy, bx, by;
	fin >> fx >> fy >> bx >> by;
	string fs, bs;
	fin >> fs >> bs;
	pair<int, int> fpos[n+1];
	fpos[0] = make_pair(fx, fy);
	for (int i=0; i<fs.length(); i++) {
		fpos[i+1] = fpos[i];
		if (fs.at(i) == 'N') {
			fpos[i+1].second++;
		} else if (fs.at(i) == 'S') {
			fpos[i+1].second--;
		} else if (fs.at(i) == 'E') {
			fpos[i+1].first++;
		} else if (fs.at(i) == 'W') {
			fpos[i+1].first--;
		}
	}
	pair<int, int> bpos[m+1];
	bpos[0] = make_pair(bx, by);
	for (int i=0; i<bs.length(); i++) {
		bpos[i+1] = bpos[i];
		if (bs.at(i) == 'N') {
			bpos[i+1].second++;
		} else if (bs.at(i) == 'S') {
			bpos[i+1].second--;
		} else if (bs.at(i) == 'E') {
			bpos[i+1].first++;
		} else if (bs.at(i) == 'W') {
			bpos[i+1].first--;
		}
	}
	long long dp[n+1][m+1];
	dp[0][0] = 0;
	// cout << "0 ";
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = 1e12;
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
			if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			dp[i][j] += dist(fpos[i], bpos[j]);
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	fout << dp[n][m] << endl;
}