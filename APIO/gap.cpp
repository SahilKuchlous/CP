#include "gap.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long findGap (int t, int n) {
	if (t == 1) {
		long long mn, mx;
		MinMax(0, 1e18, &mn, &mx);
		long long p_mn = mn, p_mx = mx;
		long long ans = 0;
		for (int i=1; i<(n+1)/2; i++) {
			MinMax(p_mn+1, p_mx-1, &mn, &mx);
			ans = max(ans, mn-p_mn);
			ans = max(ans, p_mx-mx);
			p_mn = mn;
			p_mx = mx;
		}
		ans = max(ans, mx-mn);
		return ans;
	} else {
		long long mn, mx;
		MinMax(0, 1e18, &mn, &mx);
		if (n == 2) return mx-mn;
		long long sz = (mx-mn-1+n)/n;
		long long prev = mn;
		long long pos = mn+1;
		long long ans = 0;
		for (long long i=0; i<n; i++) {
			if (pos <= pos+sz-1) MinMax(pos, pos+sz-1, &mn, &mx);
			if (mn > -1) {
				ans = max(ans, mn-prev);
				prev = mx;
			}
			pos += sz;
		}
		return max(ans, mx-prev);
	}
}