#include <iostream>
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
		long long o = 0;
		for (int i=1; i<n; i++) {
			o += max(0, a[i-1]-a[i]);
		}
		cout << o << endl;
	}
}