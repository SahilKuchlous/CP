#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		long long x = 9;
		int c = 0;
		while (x <= b) {
			x = x*10+9;
			c++;
		}
		cout << a*c << endl;
	}
}