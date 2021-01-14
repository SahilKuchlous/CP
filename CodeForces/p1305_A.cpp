#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int b[n];
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		sort(a, a+n);
		sort(b, b+n);
		for (int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		for (int i=0; i<n; i++) {
			cout << b[i] << " ";
		}
		cout << endl;
	}
}