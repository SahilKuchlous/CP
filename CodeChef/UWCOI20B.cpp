#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long oc=0, ec=0;
		long long x;
		for (int i=0; i<n; i++) {
			cin >> x;
			if (x%2 == 0) {
				ec++;
			} else {
				oc++;
			}
		}
		cout << ec*oc << endl;
	}
}