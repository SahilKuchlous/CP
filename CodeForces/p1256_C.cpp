#include <iostream>
using namespace std;
int main () {
	int n, m, d;
	cin >> n >> m >> d;
	int a[m];
	int s = 0;
	for (int i=0; i<m; i++) {
		cin >> a[i];
		s += a[i];
	}
	int o[n];
	for (int i=0; i<n; i++) {
		o[i] = 0;
	}
	int x = 0;
	for (int i=1; i<=m; i++) {
		if (s+d-1 >= n-x) {
			x = n;
			int c = n-1;
			for (int k=m; k>=i; k--) {
				for (int l=0; l<a[k-1]; l++) {
					o[c] = k;
					c--;
				}
			}
			break;
		}
		x += d-1;
		for (int j=0; j<a[i-1]; j++) {
			o[x+j] = i;
		}
		x += a[i-1];
		s -= a[i-1];
	}
	if (n-x > d-1) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			cout << o[i] << " ";
		}
		cout << endl;
	}
}