#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	vector<long long> dp;
	dp.push_back(2);
	long long cur;
	for (int i=1; i<100000; i++) {
		if (dp[i-1] > 1e9) break;
		cur = dp[i-1]+3*i+2;
		dp.push_back(cur);
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int o = 0;
		while (n >= 2) {
			n -= *prev(upper_bound(dp.begin(), dp.end(), n));
			o++;
		}
		cout << o << endl;
	}
}