#include <iostream>
#include <string>
using namespace std;
int main () {
	int k;
	while (cin >> k) {
		int c = 0;
		int s;
		long long b;
		for (int i=k+1; i<=2*k; i++) {
			s = i-k;
			b = i*k;
			if (b%s == 0) {
				c++;
			}
		}
		cout << c << endl;
		for (int i=k+1; i<=2*k; i++) {
			s = i-k;
			b = i*k;
			if (b%s == 0) {
				cout << "1/" << k << " = 1/" << b/s << " + 1/" << i << endl;
			}
		}
	}
}