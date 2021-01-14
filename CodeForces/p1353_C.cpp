#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long o = 0;
		for (long long i=1; i<=n/2; i++) {
			o += i*i;
		}
		cout << 8*o << endl;
	}
}