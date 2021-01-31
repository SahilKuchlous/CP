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
		int cur = 1, o = 1;
		for (int i=1; i<n; i++) {
			if (a[i] == a[i-1]) {
				cur++;
				o = max(o, cur);
			} else {
				cur = 1;
			}
		}
		cout << o << endl;
	}
}