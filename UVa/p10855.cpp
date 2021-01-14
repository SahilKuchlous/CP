#include <iostream>
#include <string>
using namespace std;
int main () {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		string inp;
		char a[n][n];
		for (int i=0; i<n; i++) {
			cin >> inp;
			for (int j=0; j<n; j++) {
				a[i][j] = inp[j];
			}
		}
		char b[m][m];
		for (int i=0; i<m; i++) {
			cin >> inp;
			for (int j=0; j<m; j++) {
				b[i][j] = inp[j];
			}
		}
		int o[4];
		for (int i=0; i<4; i++) {
			o[i] = 0;
		}
		char bf[m][m];
		for (int oi=0; oi<=n-m; oi++) {
			for (int oj=0; oj<=n-m; oj++) {
				for (int c=0; c<4; c++) {
					bool match = true;
					for (int i=0; i<m; i++) {
						for (int j=0; j<m; j++) {
							if (a[oi+i][oj+j] != b[i][j]) {
								match = false;
								break;
							}
						}
						if (!match) {
							break;
						}
					}
					if (match) {
						o[c]++;
					}
					for (int x=0; x<m; x++) {
						for (int y=0; y<m; y++) {
							bf[x][y] = b[m-y-1][x];
						}
					}
					for (int x=0; x<m; x++) {
						for (int y=0; y<m; y++) {
							b[x][y] = bf[x][y];
						}
					}
				}
			}
		}
		for (int i=0; i<4; i++) {
			if (i == 3) {
				cout << o[i] << endl;
				break;
			}
			cout << o[i] << " ";
		}
	}
}