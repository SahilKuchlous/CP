#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("help.in");
ofstream fout("help.out");
long long binpow (long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return res;
}
int main () {
	int n;
	fin >> n;
	vector< pair<int, int> > seg;
	int ai, bi;
	for (int i=0; i<n; i++) {
		fin >> ai >> bi;
		seg.push_back(make_pair(ai, bi));
	}
	sort(seg.begin(), seg.end());
	int ord[2*n+1];
	for (int i=0; i<n; i++) {
		ord[seg[i].first] = i+1;
		ord[seg[i].second] = -(i+1);
	}
	long long dp[n+1];
	bool closed[n+1];
	for (int i=1; i<=2*n; i++) {
		if (ord[i] > 0) {
			dp[ord[i]] = 1;
			closed[ord[i]] = false;
			int cnt = 0;
			for (int j=1; j<ord[i]; j++) {
				if (closed[j]) {
					dp[ord[i]] += dp[j]+binpow(2, cnt, 1000000007);
					cnt++;
				} else {
					dp[ord[i]] += dp[j];
				}
				dp[ord[i]] %= 1000000007;
			}
		} else {
			closed[-ord[i]] = true;
		}
	}
	long long o = 0;
	for (int i=1; i<=n; i++) {
		// cout << dp[i] << " ";
		o += dp[i];
		o %= 1000000007;
	}
	// cout << endl;
	fout << o << endl;
}