#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n;
		cin >> n;
		int x, m;
		m = 0;
		for (int i=0; i<n; i++) {
			cin >> x;
			if (x > m) {
				m = x;
			}
		}
		cout << "Case " << z+1 << ": " << m << endl; 
	}
}