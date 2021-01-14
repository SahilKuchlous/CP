#include <iostream>
using namespace std;
int main () {
	int n;
	while (true) {
		cin >> n;
		if (n == 42) {
			return 0;
		} else {
			cout << n << endl;
		}
	}
}