#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int grid[n][m];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> grid[i][j];
			}
		}
		int c1 = 0;
		for (int i=0; i<n; i++) {
			bool f = true;
			for (int j=0; j<m; j++) {
				if (grid[i][j] == 1) f = false;
			}
			if (f) c1++;
		}
		int c2 = 0;
		for (int j=0; j<m; j++) {
			bool f = true;
			for (int i=0; i<n; i++) {
				if (grid[i][j] == 1) f = false;
			}
			if (f) c2++;
		}
		int moves = min(c1, c2);
		if (moves%2 == 0) {
			cout << "Vivek" << endl;
		} else {
			cout << "Ashish" << endl;
		}
	}
}