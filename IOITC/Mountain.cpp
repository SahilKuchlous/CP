#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=0; i<n+1; i++) {
		a[i] = 0;
	}
	while (true) {
		char c;
		cin >> c;
		if (c == 'I') {
			int s, e, d;
			cin >> s >> e >> d;
			int dif = 0;
			for (int i=s; i<=e; i++) {
				dif = a[i-1]+d-a[i];
				a[i] = a[i-1]+d;
			}
			for (int i=e+1; i<n+1; i++) {
				a[i] += dif;
			}
			/*
			for (int i=0; i<n+1; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			*/
		} else if (c == 'Q') {
			int h;
			cin >> h;
			for (int i=0; i<n+1; i++) {
				if (a[i] > h) {
					cout << (i-1) << endl;
					break;
				} else if (i == n) {
					cout << i << endl;
				}
			}
		} else if (c == 'E') {
			break;
		}
	}
}