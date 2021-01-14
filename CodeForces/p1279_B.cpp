#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		long long sum = 0;
		int rem = 0;
		int out = -1;
		for (int i=0; i<n; i++) {
			if (a[i] > rem) {
				sum += rem;
				if (sum > s) {
					break;
				}
				rem = a[i];
				out = i+1;
			} else {
				sum += a[i];
				if (sum > s) {
					break;
				}
			}
		}
		if (sum + rem <= s) {
			out = 0;
		}
		cout << out << endl;
	}
}