#include <iostream>
using namespace std;
int main () {
	int n, s;
	cin >> n >> s;
	if (s < 2*n) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i=0; i<n-1; i++) {
			cout << "2 ";
			s -= 2;
		}
		cout << s << endl;
		cout << 1 << endl;
	}
}