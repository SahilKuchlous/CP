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
		int depth[n+1];
		depth[0] = 0;
		depth[1] = 1;
		int ind = 0;
		for (int i=2; i<n; i++) {
			if (a[i] > a[i-1]) {
				depth[i] = depth[ind]+1;
			} else {
				depth[i] = depth[++ind]+1;
			}
		}
		cout << depth[n-1] << endl;
	}
}