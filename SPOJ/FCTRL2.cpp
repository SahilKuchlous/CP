#include <iostream>
#include <string>
using namespace std;
int main () {
	int t, n, l, p, c;
	int f[200];
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		f[0] = 1;
		l = 1;
		c = 0;
		for (int i=2; i<=n; i++) {
			for (int j=0; j<l; j++) {
				p = f[j]*i+c;
				cout << f[j] << " ";
				// cout << p << " ";
				f[j] = p%10;
				c = (p-f[j])/10;
			}
			if (c > 0) {
				f[l] = c;
				c = 0;
				l++;
			}
			cout << endl;
		}
		for (int i=l-1; i>-1; i--) {
			cout << f[i];
		}
		cout << endl;
	}
	return 0;
}