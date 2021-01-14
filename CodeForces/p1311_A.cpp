#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << endl;
		} else if (a < b) {
			cout << ((b-a)%2==0?2:1) << endl;
		} else {
			cout << ((a-b)%2==0?1:2) << endl;
		}
	}
}