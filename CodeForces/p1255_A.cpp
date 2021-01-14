#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int n = abs(a-b);
		int o = n/5;
		if (n%5 == 1 || n%5 == 2) {
			o++;
		} else if (n%5 == 3 || n%5 == 4) {
			o += 2;
		}
		cout << o << endl;
	}
}