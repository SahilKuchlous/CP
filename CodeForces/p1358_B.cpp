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
		int o = -1;
		for (int i=n-1; i>=0; i--) {
			if (a[i] <= i+1) {
				o = i;
				break;
			}
		}
		cout << o+2 << endl;
	}
}