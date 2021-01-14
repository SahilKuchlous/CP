#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		cout << 2*min(x, y) + max(0, abs(x-y)*2-1) << endl;
	}
}