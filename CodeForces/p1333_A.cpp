#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n==2 && m==2) {
			cout << "WB" << endl << "BB" << endl;
			continue;
		}
		if (n == 2) {
			cout << "WW";
			for (int i=0; i<m-2; i++) {
				cout << "B";
			}
			cout << endl;
			for (int i=0; i<m; i++) {
				cout << "B";
			}
			cout << endl;
			continue;
		}
		cout << "W";
		for (int i=0; i<m-1; i++) {
			cout << "B";
		}
		cout << endl;
		cout << "W";
		for (int i=0; i<m-1; i++) {
			cout << "B";
		}
		cout << endl;
		for (int i=0; i<n-2; i++) {
			for (int j=0; j<m; j++) {
				cout << "B";
			}
			cout << endl;
		}
	}
}