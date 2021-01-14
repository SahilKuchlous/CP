#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("movie.in");
ofstream fout("movie.out");
int main () {
	ios_base::sync_with_stdio(false);
	fin.tie(0);
	int n, l;
	fin >> n >> l;
	vector<long long> starts[n];
	int time[n];
	int ai, bi, ci;
	for (int i=0; i<n; i++) {
		fin >> ai >> bi;
		time[i] = ai;
		for (int j=0; j<bi; j++) {
			fin >> ci;
			starts[i].push_back(ci);
		}
	}
	for (int i=0; i<n; i++) {
		sort(starts[i].begin(), starts[i].end());
	}
	long long dp[1<<n];
	dp[0] = 0;
	int o = 100;
	vector<long long>::iterator it;
	for (int i=1; i<(1<<n); i++) {
		dp[i] = -1;
		int cnt = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				cnt++;
				it = upper_bound(starts[j].begin(), starts[j].end(), dp[i-(1<<j)]);
				if (dp[i-(1<<j)] > -1 && it != starts[j].begin()) {
					dp[i] = max(dp[i], (*prev(it))+time[j]);
				}
			}
		}
		if (dp[i] >= l) o = min(o, cnt);
	}
	if (o == 100) {
		fout << -1 << endl;
	} else {
		fout << o << endl;
	}
}