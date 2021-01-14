#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int dig (long long n) {
	int o = 0;
	while (n > 0) {
		n /= 10;
		o++;
	}
	return o;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long o = 0;
		while (true) {
			int d = dig(n);
			long long new_n = n;
			if (d > 1) {
				o += n/(int)pow(10,d-1)*(int)pow(10,d-1);
				new_n -= n/(int)pow(10,d-1)*(int)pow(10,d-1);
				new_n += n/(int)pow(10,d-1)*(int)pow(10,d-2);
				n = new_n;
			} else {
				o += n;
				break;
			}
		}
		cout << o << endl;
	}
}