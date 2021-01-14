#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main () {
	int n;
	int t = 0;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		t++;
		cout << "Case " << t << ":" << endl;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int m, q;
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> q;
			int s = a[0]+a[1];
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (abs(a[i]+a[j] - q) < abs(s-q)) {
						s = a[i]+a[j];
					}
				}
			}
			cout << "Closest sum to " << q << " is " << s << "." << endl;
		}
	}
}