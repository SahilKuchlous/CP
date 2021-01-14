#include <iostream>
#include <set>
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
	set<int> d;
	int ca = 0;
	int cb = 0;
	int o = 0;
	while (true) {
		if (b[cb] != a[ca]) {
			d.insert(b[cb]);
			cb++;
			o++;
		} else {
			d.insert(b[cb]);
			cb++;
			while (d.find(a[ca]) != d.end()) {
				ca++;
				if (ca == n) {
					break;
				}
			}
			if (ca == n) {
				break;
			}
		}
	}
	cout << o << endl;
}