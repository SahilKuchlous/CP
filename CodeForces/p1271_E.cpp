#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long n, k;
long long count (long long x) {
	long long o = 0;
	int dif = (int)log2(n)-(int)log2(x);
	o += pow(2, dif)-1;
	if (n < (x<<dif)) {
		o += 0;
	} else if (n > (x<<dif)+(1L<<dif)-1) {
		o += pow(2, dif);
	} else {
		o += (n & ((1L<<dif)-1)) + 1;
	}
	if (x%2 == 0) {
		o += count(x+1);
	}
	return o;
}
int main () {
	cin >> n >> k;
	long long l = 1, u = n/2;
	long long m;
	long long o = 1;
	while (l <= u) {
		m = (l+u)/2;
		if (count(2*m) >= k) {
			l = m+1;
			o = 2*m;
		} else {
			u = m-1;
		}
	}
	l = 0;
	u = (n-1)/2;
	while (l <= u) {
		m = (l+u)/2;
		if (count(2*m+1) >= k) {
			l = m+1;
			o = max(o, 2*m+1);
		} else {
			u = m-1;
		}
	}
	cout << o << endl;
}