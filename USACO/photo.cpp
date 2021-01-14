#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("photo.in");
ofstream fout("photo.out");
int main () {
	int n, m;
	fin >> n >> m;
	int ai, bi;
	vector< pair<int, int> > ranges;
	vector<int> ends[n+10];
	for (int i=0; i<m; i++) {
		fin >> ai >> bi;
		ranges.push_back({ai, bi});
		ends[bi].push_back(ai);
	}
	int back[n+10];
	back[0] = 0;
	int cur = 0;
	for (int i=1; i<=n+1; i++) {
		for (auto j: ends[i-1]) {
			cur = max(cur, j);
		}
		back[i] = cur;
	}
	int front[n+10];
	cur = n+1;
	for (int i=n+1; i>=0; i--) {
		for (auto j: ends[i]) {
			cur = min(cur, j-1);
		}
		front[i] = min(i-1, cur);
	}
	int dp[n+10];
	dp[0] = 0;
	for (int i=1; i<=n+1; i++) {
		dp[i] = -1;
		for (int j=back[i]; j<=front[i]; j++) {
			if (dp[j] != -1) dp[i] = max(dp[i], dp[j]+1);
		}
	}
	if (dp[n+1] > 0) {
		fout << dp[n+1]-1 << endl;
	} else {
		fout << -1 << endl;
	}
}