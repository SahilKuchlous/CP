#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long a, b, n, s;
		cin >> a >> b >> n >> s;
		if (a*n+b < s) {
			cout << "NO" << endl;
			continue;
		}
		if (b >= n-1) {
			cout << "YES" << endl;
			continue;
		}
		if (s%n <= b) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}