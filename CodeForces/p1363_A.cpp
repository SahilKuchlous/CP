#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		int ec = 0, oc = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i]%2 == 0) {
				ec++;
			} else {
				oc++;
			}
		}
		bool pos = false;
		for (int i=0; i<=ec; i++) {
			for (int j=1; j<=oc; j+=2) {
				if (i+j == x) pos = true;
			}
		}
		cout << (pos ? "Yes":"No") << endl;
	}
}