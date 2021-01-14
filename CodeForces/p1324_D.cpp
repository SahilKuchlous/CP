#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[n];
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	int dif[n];
	for (int i=0; i<n; i++) {
		dif[i] = a[i]-b[i];
	}
	sort(dif, dif+n);
	int fp = n-1;
	long long o = 0;
	for (int i=0; i<n; i++) {
		while (-dif[i] < dif[fp]) {
			if (fp <= i) {
				break;
			}
			fp--;
		}
		if (fp >= i) {
			o += n-fp-1;
		} else {
			o += n-i-1;
		}
	}
	cout << o << endl;
}