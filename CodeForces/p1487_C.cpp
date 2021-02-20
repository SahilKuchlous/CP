#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	int o[n][n];
	for (int i=0; i<n; i++) {
		for (int j=1; j<n; j++) {
			if (j < (n+1)/2) {
				o[i][(i+j)%n] = 1;
			} else if (n%2 == 0 && j == n/2) {
				o[i][(i+j)%n] = 0;
			} else {
				o[i][(i+j)%n] = -1;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			cout << o[i][j] << " ";
		}
	}
	cout << endl;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}