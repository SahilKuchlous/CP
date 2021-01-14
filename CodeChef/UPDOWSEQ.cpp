#include <iostream>
#include <vector>
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
		int dp1[n];
		int dp2[n];
		dp1[0] = 0;
		dp2[0] = 0;
		bool up = true;
		for (int i=0; i<n-1; i++) {
			if ((a[i+1]<a[i] && up) || (a[i+1]>a[i] && !up)) {
				if (up) {
					dp1[i+1] = 0;
					up = true;
				} else {
					dp1[i+1] = 1;
					up = false;
				}
				dp2[i+1] = dp1[i]+2;
			} else {
				dp1[i+1] = dp1[i]+1;
				dp2[i+1] = dp2[i]+1;
				up = !up;
			}
		}
		/*
		for (int i=0; i<=n; i++) {
			cout << dp1[i] << " ";
		}
		cout << endl;
		for (int i=0; i<=n; i++) {
			cout << dp2[i] << " ";
		}
		cout << endl;
		*/
		int m = 0;
		for (int i=0; i<n; i++) {
			if (dp2[i] > m) {
				m = dp2[i];
			}
		}
		if (dp1[n-1]+1 > m) {
			m = dp1[n-1]+1;
		}
		cout << m+1 << endl;
	}
}