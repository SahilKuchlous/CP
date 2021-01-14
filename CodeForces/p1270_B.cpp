#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		pair<int, int> o = {-1, -1};
		for (int i=1; i<n; i++) {
			if (a[i]-a[i-1] > 1 || a[i-1]-a[i] > 1) {
				o = {i, i+1};
				break;
			}
		}
		if (o == make_pair(-1, -1)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << o.first << " " << o.second << endl;
		}
	}
}