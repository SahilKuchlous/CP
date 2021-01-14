#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	long long s[n];
	for (int i=0; i<m; i++) {
		s[i] = a[i];
	}
	for (int i=m; i<n; i++) {
		s[i] = s[i-m]+a[i];
	}
	long long o[n];
	o[0] = a[0];
	for (int i=1; i<n; i++) {
		o[i] = o[i-1]+s[i];
	}
	for (int i=0; i<n; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}