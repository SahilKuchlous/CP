#include <iostream>
using namespace std;
int main () {
	int n, x, y;
	cin >> n >> x >> y;
	int o = 0;
	for (int i=0; i<n; i++) {
		if (x & (1<<i)) {
			o = i;
			break;
		}
		if (y & (1<<i)) {
			o = i;
			break;
		}
	}
	cout << n-o-1 << endl;
}