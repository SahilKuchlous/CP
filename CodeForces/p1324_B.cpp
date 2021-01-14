#include <iostream>
#include <map>
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
		int first[n+1];
		int last[n+1];
		for (int i=0; i<=n; i++) {
			first[i] = last[i] = -1;
		}
		for (int i=0; i<n; i++) {
			if (first[a[i]] == -1) {
				first[a[i]] = i;
			} else {
				last[a[i]] = i;
			}
		}
		bool pos = false;
		for (int i=1; i<=n; i++) {
			if (first[i] > -1 && last[i] > -1 && last[i]-first[i] > 1) {
				pos = true;
			}
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}