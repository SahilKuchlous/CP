#include <iostream>
#include <set>
#include <cmath>
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
		long long mod = ceil(1.0*1e9/n)*n;
		set<long long> vis;
		bool pos = true;
		for (int i=0; i<n; i++) {
			if (vis.find((mod+i+a[i])%n) == vis.end()) {
				vis.insert((mod+i+a[i])%n);
			} else {
				pos = false;
				break;
			}
		}
		cout << (pos ? "YES":"NO") << endl;
	}
}