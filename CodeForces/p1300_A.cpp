#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int sum = 0;
		int zero = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
			if (a[i] == 0) {
				zero++;
			}
		}
		if (sum+zero == 0) {
			cout << zero+1 << endl;
		} else {
			cout << zero << endl;
		}
	}
}