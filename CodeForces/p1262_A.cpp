#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n][2];
		for (int i=0; i<n; i++) {
			cin >> a[i][0] >> a[i][1];
		}
		int o1, o2;
		o1 = 0;
		o2 = 1000000000;
		for (int i=0; i<n; i++) {
			if (a[i][0] > o1) {
				o1 = a[i][0];
			}
			if (a[i][1] < o2) {
				o2 = a[i][1];
			}
		}
		if (o2 < o1) {
			cout << o1-o2 << endl;
		} else {
			cout << 0 << endl;
		}
	}
}