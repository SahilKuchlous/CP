#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(int a, int b) { 
	if (a == b) 
		return a;  
	if (a > b) 
	    return gcd(a-b, b); 
	return gcd(a, b-a); 
} 
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int p[n];
		for (int i=0; i<n; i++) {
			cin >> p[i];
			p[i]/=100;
		}
		sort(p, p+n, greater<int>());
		int x, a, y, b, t;
		cin >> x >> a >> y >> b;
		if (x < y) {
			t = y;
			y = x;
			x = t;
			t = b;
			b = a;
			a = t;
		}
		long long k;
		cin >> k;
		long long ps[n];
		ps[0] = p[0];
		for (int i=1; i<n; i++) {
			ps[i] = p[i]+ps[i-1];
		}
		int o = -1;
		long long s;
		int c;
		long long m = (a*b)/gcd(a, b);
		for (int i=1; i<=n; i++) {
			s = 0;
			c = -1;
			if (i/m > 0) {
				s += ps[c+i/m]*(x+y);
				c += i/m;
			}
			// cout << s << endl;
			if (i/a-i/m > 0) {
				if (c >= 0) {
					s += (ps[c+i/a-i/m]-ps[c])*x;	
				} else {
					s += ps[c+i/a-i/m]*x;
				}
				c += i/a-i/m;
			}
			// cout << s << endl;
			if (i/b-i/m > 0) {
				if (c >= 0) {
					// cout << c+i/b-i/m << endl;
					s += (ps[c+i/b-i/m]-ps[c])*y;
				} else {
					s += ps[c+i/b-i/m]*y;
				}
				c += i/b-i/m;
			}
			// cout << s << endl;
			// cout << endl;
			if (s >= k) {
				o = i;
				break;
			}
		}
		cout << o << endl;
	}
}