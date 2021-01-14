#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		char grid[n][m];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> grid[i][j];
			}
		}
		int o = 0;
		for (int i=0; i<n; i++) {
			if (grid[i][m-1] == 'R') o++;
		}
		for (int j=0; j<m; j++) {
			if (grid[n-1][j] == 'D') o++;
		}
		cout << o << endl;
	}
}