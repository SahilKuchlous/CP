#include <iostream>
using namespace std;
int main () {
	for (int i=0; i<8; i++) {
		int a;
		cin >> a;
		if (a == 9) {
			cout << "F" << endl;
			return 0;
		}
	}
	cout << "S" << endl;
}