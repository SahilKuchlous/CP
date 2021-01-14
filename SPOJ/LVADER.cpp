#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long c (int n, int k) {
	if (k < n-k) k = n-k;
	long o = 1;
	for (int i=1; i<k; i++) {
		o *= n-i+1;
		o /= i;
		o %= 1000000007;
	}
	return o;
}

int main () {
	int t, x1, y1, x2, y2, x, y, n, m;
	cin >> t;
	for (int z=0; z<t; z++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x = x2-x1;
		y = y2-y1;
		n = max(x, y);
		m = min(x, y);
		long long o = 0;
		for (int k=0; k<=m; k++) {
			o += (c(n+m-2*k, n-1)*c(n, k))%1000000007;
		}
		cout << o << endl;
	}
}