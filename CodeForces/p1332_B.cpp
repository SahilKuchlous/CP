#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int m = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			m = max(m, a[i]);
		}
		int col[n];
		for (int i=0; i<n; i++) {
			col[i] = -1;
		}
		int cur = 1;
		bool req;
		for (int i=2; i*i<=m; i++) {
			req = false;
			for (int j=0; j<n; j++) {
				if (col[j] == -1 && a[j]%i == 0) {
					req = true;
					col[j] = cur;
				}
			}
			if (req) cur++;
		}
		cout << cur-1 << endl;
		for (int i=0; i<n; i++) {
			cout << col[i] << " ";
		}
		cout << endl;
	}
}