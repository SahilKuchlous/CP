#include <iostream>
#include <algorithm>
using namespace std;
long long dig_cube (long long n) {
	long long d, s = 0, nc = n;
	while (n > 0) {
		d = n%10;
		n /= 10;
		s += d;
	}
	return nc+s*s*s;
}
int main () {
	int n, s;
	cin >> n >> s;
	long long e[n];
	for (long long i=0; i<n; i++) {
		cin >> e[i];
	}
	pair<long long, long long> a[n][n+1];
	a[0][0].first = 0;
	a[0][0].second = dig_cube(s);
	a[0][1].first = e[0]*s;
	a[0][1].second = s;
	for (int i=1; i<n; i++) {
		a[i][0].first = 0;
		a[i][0].second = dig_cube(a[i-1][0].second);
		for (int j=1; j<=i; j++) {
			a[i][j].first = max(a[i-1][j-1].first + a[i-1][j-1].second*e[i], a[i-1][j].first);
			a[i][j].second = dig_cube(a[i-1][j].second);
		}
		a[i][i+1].first = a[i-1][i].first + s*e[i];
		a[i][i+1].second = s;
	}
	long long m=0;
	for (int i=0; i<=n; i++) {
		// cout << a[n-1][i].first << " ";
		// cout << a[n-1][i].second << endl;
		if (a[n-1][i].first > m) {
			m = a[n-1][i].first;
		}
	}
	cout << m << endl;
	return 0;
}