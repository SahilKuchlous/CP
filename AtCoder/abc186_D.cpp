#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	long long a[n];
	long long pre = 0, suf = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		suf += a[i];
	}
	sort(a, a+n);
	long long o = 0;
	for (int i=0; i<n; i++) {
		suf -= a[i];
		o += a[i]*i-pre;
		o += suf-a[i]*(n-i-1);
		pre += a[i];
	}
	cout << o/2 << endl;
}