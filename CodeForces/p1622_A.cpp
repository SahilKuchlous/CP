#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a[3];
		for (int i=0; i<3; i++) {
			cin >> a[i];
		}
		sort(a, a+3);
		if (a[2] == a[0]+a[1] || (a[0] == a[1] && a[2]%2 == 0) || (a[1] == a[2] && a[0]%2 == 0)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}