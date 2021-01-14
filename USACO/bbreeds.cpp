#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
ifstream fin("bbreeds.in");
ofstream fout("bbreeds.out");
int main () {
	string inp;
	fin >> inp;
	int n = inp.length();
	int seq[n+1];
	for (int i=1; i<=n; i++) {
		if (inp.at(i-1) == '(') {
			seq[i] = 1;
		} else {
			seq[i] = -1;
		}
	}
	map< pair<int, int>, int > dp[n+1];
	dp[0][make_pair(0, 0)] = 1;
	for (int i=1; i<=n; i++) {
		for (auto j: dp[i-1]) {
			if (j.first.first+seq[i] >= 0) {
				dp[i][make_pair(j.first.first+seq[i], j.first.second)] += j.second;
				dp[i][make_pair(j.first.first+seq[i], j.first.second)] %= 2012;
			}
			if (j.first.second+seq[i] >= 0) {
				dp[i][make_pair(j.first.first, j.first.second+seq[i])] += j.second;
				dp[i][make_pair(j.first.first, j.first.second+seq[i])] %= 2012;
			}

		}
	}
	fout << dp[n][make_pair(0, 0)] << endl;
}