#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	if (n%2 == 0) {
		cout << n+4 << " " << 4 << endl;
	} else {
		cout << n+9 << " " << 9 << endl;
	}
}