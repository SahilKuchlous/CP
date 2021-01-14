#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int seg[4000000];
long long fact[100001];
long long mi[100001];
long long pow (int a, int b, int m) {
	long long x = 1;
	long long y = a;
	while (b>0) {
		if (b%2 == 1) {
			x = x*y;
			if (x>m) x%=m;
		}
		y = y*y;
		if (y>m) y%=m;
		b /= 2;
	}
	return x;
}
long long ie (int n, int m) {
	return pow(n, m-2, m);
}
void update (int l, int r, int x, int y, int a) {
	if (y<l || x>r) {
		return;
	}
	if (l<=x && y<=r) {
		seg[a]++;
		return;
	}
	int m = (x+y)/2;
	update(l, r, x, m, 2*a+1);
	update(l, r, m+1, y, 2*a+2);
}
int query (int q, int x, int y, int a) {
	if (q<x || q>y) {
		return 0;
	}
	if (x == y) {
		return seg[a];
	}
	int r = seg[a];
	int m = (x+y)/2;
	r += query(q, x, m, 2*a+1);
	r += query(q, m+1, y, 2*a+2);
	return r;
}
long long npk (int n, int k) {
	long long o = 1;
	for (int i=n-k+1; i<=n; i++) {
		o *= i;
		o = o%1000000007;
	}
	return o;
}
int main () {
	int n, k;
	cin >> n >> k;
	fact[0] = 0;
	fact[1] = 1;
	for (int i=2; i<n; i++) {
		fact[i] = (fact[i-1]*i)%1000000007;
	}
	string a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	sort(a, a+n);
	map<string, int> m;
	for (int i=0; i<n; i++) {
		m[a[i]] = i;
	}
	string l = "";
	vector<int> x;
	for (auto c: s) {
		l += c;
		if (m.find(l) != m.end()) {
			x.push_back(m[l]);
			l = "";
		}
	}
	for (int i=0; i<4*n; i++) {
		seg[i] = 0;
	}
	long long o = 0;
	for (int i=0; i<k; i++) {
		update(x[i]+1, n-1, 0, n-1, 0);
		int r = query(x[i], 0, n-1, 0);
		// cout << i << " " << x[i] << " " << r << endl;
		o += (x[i]-r)*npk(n-i-1, k-i-1);
		o = o%1000000007;
	}
	cout << o+1 << endl;
}