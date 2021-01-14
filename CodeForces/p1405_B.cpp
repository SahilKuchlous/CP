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
		long long psum = 0;
		long long o = 0;
		for (int i=0; i<n; i++) {
			psum += a[i];
			o = min(o, psum);
		}
		cout << -o << endl;
	}
}