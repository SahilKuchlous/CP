#include <iostream>
#include <stdlib.h> 
using namespace std;
int main () {
	int n, a, b;
	cin >> n;
	int d[n+1];
	d[0] = 0;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		d[i+1] = d[i]+(a-b);
	}
	int w = 0, l = 0;
	for (int i=1; i<=n; i++) {
		if (abs(d[i]) > l) {
			l = abs(d[i]);
			if (d[i] < 0) {
				w = 2;
			} else {
				w = 1;
			}
		}
	}
	cout << w << " " << l << endl;
	return 0;
}