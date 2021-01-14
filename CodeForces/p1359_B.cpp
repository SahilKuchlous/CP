#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		y = min(y, 2*x);
		char grid[n][m];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> grid[i][j];
			}
		}
		int o = 0;
		int cnt;
		for (int i=0; i<n; i++) {
			cnt = 0;
			for (int j=0; j<m; j++) {
				if (grid[i][j] == '.') {
					cnt++;
				} else {
					o += y*(cnt/2) + (cnt%2==0?0:x);
					cnt = 0;
				}
			}
			o += y*(cnt/2) + (cnt%2==0?0:x);
		}
		cout << o << endl;
	}
}