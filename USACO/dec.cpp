#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dec.in");
ofstream fout("dec.out");
int main () {
	int n, b;
	fin >> n >> b;
	vector< pair<int, int> > bonus[n+1];
	int ai, bi, ci;
	for (int i=0; i<b; i++) {
		fin >> ai >> bi >> ci;
		bonus[ai].push_back(make_pair(bi, ci));
	}
	for (int i=0; i<=n; i++) {
		sort(bonus[i].begin(), bonus[i].end());
	}
	int skill[n][n+1];
	for (int i=0; i<n; i++) {
		for (int j=1; j<=n; j++) {
			fin >> ai;
			skill[i][j] = ai;
		}
	}
	int dp[1<<n];
	int cnt;
	for (int i=0; i<(1<<n); i++) {
		dp[i] = 0;
		cnt = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				cnt++;
			}
		}
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				dp[i] = max(dp[i], dp[i-(1<<j)]+skill[j][cnt]);
			}
		}
		for (auto j: bonus[cnt]) {
			if (dp[i] >= j.first) {
				dp[i] += j.second;
			}
		}
	}
	fout << dp[(1<<n)-1] << endl;
}