#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int rows[n][m], cols[m][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> rows[i][j];
			}
		}
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cin >> cols[i][j];
			}
		}
		int cid = 0;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (cols[i][j] == rows[0][0]) {
					cid = i;
				}
			}
		}
		int ord[n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (cols[cid][i] == rows[j][0]) {
					ord[i] = j;
					break;
				}
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << rows[ord[i]][j] << " ";
			}
			cout << '\n';
		}
	}
}