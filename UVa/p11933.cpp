#include <iostream>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int a = 0;
		int b = 0;
		bool f = true;
		for (int i=0; i<32; i++) {
			if ((n&(1<<i)) > 0) {
				if (f) {
					a = a|(1<<i);
				} else {
					b = b|(1<<i);
				}
				f = !f;
			}
		}
		cout << a << " " << b << endl;
	}
}