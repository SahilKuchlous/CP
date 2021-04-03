#include <iostream>
using namespace std;
void solve () {
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int w, b;
	cin >> w >> b;
	if (k1+k2 >= 2*w && 2*n-k1-k2 >= 2*b) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}