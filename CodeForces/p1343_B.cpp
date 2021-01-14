#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n%4 == 0) {
			cout << "YES" << endl;
			int even[n/2], odd[n/2];
			for (int i=0; i<n/2; i++) {
				even[i] = 4*i+2;
				if (i%2 == 0) {
					odd[i] = 4*i+1;
				} else {
					odd[i] = 4*i+3;
				}
			}
			for (int i=0; i<n/2; i++) {
				cout << even[i] << " ";
			}
			for (int i=0; i<n/2; i++) {
				cout << odd[i] << " ";
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}