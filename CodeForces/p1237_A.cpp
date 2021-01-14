#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int x;
	int a = 1;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x%2 == 0) {
			cout << x/2 << endl;
		} else {
			cout << (x+a)/2 << endl;
			a = -a;
		}
	}
}