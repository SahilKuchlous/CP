#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int m = 0;
	for (int i=0; i<n; i++) {
		if (a[i]+i+1 > m) {
			m = a[i]+i+1;
		}
	}
	int o[n];
	o[n-1] = m;
	for (int i=0; i<n-1; i++) {
		if (a[i] + n > m-1) {
			m = a[i]+n;
			o[i] = a[i]+n;
		} else {
			m--;
			o[i] = m;
		}
	}
	for (int i=n-1; i>=0; i--) {
		cout << o[i] << " ";
	}
	cout << endl;
}