#include <iostream>
#include <cmath>
#include <set>
using namespace std;
int n, p, q, x, y;
int a[1000100];
int psum[1000100];
int min_p[1000100];
int o = 1e9+1;
int shift = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p >> q >> x >> y;
	char inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		if (inp == '+') a[i] = 1;
		if (inp == '-') a[i] = -1;
		if (i == 0) {
			psum[i] = p;
		} else {
			psum[i] = psum[i-1];
		}
		psum[i] += a[i];
		min_p[i] = psum[i];
		if (i > 0) min_p[i] = min(min_p[i], min_p[i-1]);
	}
	for (int i=0; i<n; i++) {
		int ttl = psum[n-1];
		int cost = i*y;
		int min_v = shift+min_p[n-i-1];
		if (min_v < 0) {
			int inc = (-min_v+1)/2;
			ttl += 2*inc;
			cost += x*inc;
		}
		cost += x*abs(ttl-q)/2;
		o = min(o, cost);
		shift += a[n-i-1];
	}
	cout << o << endl;
}
