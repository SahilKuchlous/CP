#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int grid[n];
		string inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			for (int j=0; j<n; j++) {
				if (inp.at(j) == '1') {
					grid[i] = j;
					break;
				}
			}
		}
		int o = 0;
		int a, b;
		for (int i=0; i<n; i++) {
			a = 100000;
			b = -1;
			for (int j=i; j<n; j++) {
				a = min(a, grid[j]);
				b = max(b, grid[j]);
				if (b-a == j-i) o++;
			}
		}
		cout << o << endl;
	}
}