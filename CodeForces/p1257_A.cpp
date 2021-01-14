#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(abs(a-b)+x, n-1) << endl;
	}
}