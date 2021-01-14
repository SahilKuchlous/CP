#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a[4];
		for (int i=0; i<4; i++) cin >> a[i];
		int cnt = 0;
		for (int i=0; i<4; i++) {
			if (a[i]%2 == 1) cnt++;
		}
		if (cnt <= 1) {
			cout << "Yes" << endl;
			continue;
		}
		if (a[0] == 0 || a[1] == 0 || a[2] == 0) {
			cout << "No" << endl;
			continue;
		}
		a[0]--; a[1]--; a[2]--; a[3] += 3;
		cnt = 0;
		for (int i=0; i<4; i++) {
			if (a[i]%2 == 1) cnt++;
		}
		if (cnt <= 1) {
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
}