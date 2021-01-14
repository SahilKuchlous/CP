#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		bool pos = false;
		for (int i=0; i<ceil(sqrt(d)); i++) {
			if (ceil(d*1.0/(i+1))+i <= n) {
				pos = true;
				break;
			}
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}