#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve () {
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long presum[n];
	presum[0] = a[0];
	for (int i=1; i<n; i++) {
		presum[i] = presum[i-1]+a[i];
	}
	vector<long long> suf;
	long long cur_min = 1e16;
	for (int i=n-1; i>=0; i--) {
		cur_min = min(cur_min, presum[i]);
		suf.push_back(cur_min);
	}
	reverse(suf.begin(), suf.end());
	int best_s = -1, best_l = 0;
	for (int i=0; i<n; i++) {
		long long maxsum = presum[i]-a[i]+m;
		int l = upper_bound(suf.begin(), suf.end(), maxsum)-suf.begin()-i;
		if (l > best_l) {
			best_l = l;
			best_s = i+1;
		}
	}
	cout << best_l << " " << best_s << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}