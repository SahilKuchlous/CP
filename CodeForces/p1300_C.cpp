#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	long long a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	bool found;
	int o = 0;
	for (int i=30; i>=0; i--) {
		found = false;
		for (int j=0; j<n; j++) {
			if ((1<<i)&a[j]) {
				if (found) {
					found = false;
					o = 0;
					break;
				} else {
					found = true;
					o = j;
				}
			}
		}
		if (found) {
			break;
		}
	}
	cout << a[o] << " ";
	for (int i=0; i<n; i++) {
		if (i != o) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}