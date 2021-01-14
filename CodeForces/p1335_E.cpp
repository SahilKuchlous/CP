#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, inc, red, swp;
vector<int> heights;
long long total = 0;
long long presum[100001];
long long calc (int m) {
	int pos = lower_bound(heights.begin(), heights.end(), m) - heights.begin();
	long long cost = min(1ll*m*pos-presum[pos], presum[n]-presum[pos]-1ll*m*(n-pos))*swp;
	if (1ll*m*n-total > 0) {
		cost += 1ll*inc*(1ll*m*n-total);
	} else {
		cost += 1ll*red*(total-1ll*m*n);
	}
	return cost;
}
int main () {
	cin >> n >> inc >> red >> swp;
	if (swp > inc+red) swp = inc+red;
	int inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		heights.push_back(inp);
		total += inp;
	}
	sort(heights.begin(), heights.end());
	presum[0] = 0;
	for (int i=1; i<=n; i++) {
		presum[i] = presum[i-1]+heights[i-1];
	}
	int l = heights[0], r = heights[n-1], m;
	long long o = 1e18;
	while (l <= r) {
		int m1 = l+(r-l)/3;
		int m2 = l+2*(r-l)/3;
		long long c1 = calc(m1);
		long long c2 = calc(m2);
		o = min(o, min(c1, c2));
		if (c1 < c2) {
			r = m2-1;
		} else {
			l = m1+1;
		}
	}
	cout << o << endl;
}