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
		sort(a, a+n);
		int u, d;
		bool f = true;
		if (n%2 == 1) {
			cout << a[n/2] << " ";
			u = (n/2)+1;
			d = (n/2)-1;
		} else {
			u = (n/2);
			d = (n/2)-1;
		}
		while (d >= 0) {
			if (f) {
				cout << a[u] << " ";
				u++;
			} else {
				cout << a[d] << " ";
				d--;
			}
			f = !f;
		}
		cout << endl;		
	}
}