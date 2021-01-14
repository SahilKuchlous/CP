#include <iostream>
using namespace std;
int main () {
	int t, x, s;
	cin >> t >> x >> s;
	if (s < t) {
		cout << "NO" << endl;
		return 0;
	}
	if ((s-t)%x == 0 || ((s-t)%x == 1 && s-t>1)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}