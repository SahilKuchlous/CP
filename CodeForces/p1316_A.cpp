#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int t = 0;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			t += inp;
		}
		cout << min(m, t) << endl;
	}
}