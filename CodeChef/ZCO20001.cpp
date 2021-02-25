#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, x;
		cin >> n >> x;
		long long o = 0;
		for (int i=0; i<n; i++) {
			if ((1ll<<i)&x) {
				o |= (1ll<<(n-i-1));
			}
		}
		cout << o << endl;
	}
}