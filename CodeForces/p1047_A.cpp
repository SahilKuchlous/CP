#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	if (n%3 == 0 || n%3 == 1) {
		cout << n-2 << " " << 1 << " " << 1 << endl;
	} else {
		cout << n-3 << " " << 2 << " " << 1 << endl;
	}
}