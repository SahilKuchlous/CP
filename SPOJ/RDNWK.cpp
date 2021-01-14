#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int c=1; c<=t; c++) {
		int n;
		cin >> n;
		int wts[n+1][n+1];
		int w;
		for (int i=1; i<=n; i++) {
			for (int j=i+1; j<=n; j++) {
				cin >> w;
				wts[i][j] = wts[j][i] = w;
			}
		}
		int p;
		cin >> p;
		int ranks[p+1];
		for (int i=1; i<=p; i++) {
			cin >> ranks[i];
		}
		int ans[p+1][n+1][n+1];
		for (int j=1; j<=n; j++) {
			for (int k=1; k<=n; k++) {
				if (j == k) {
					ans[0][j][k] = 0;
				} else if (wts[j][k] != -1) {
					ans[0][j][k] = wts[j][k];
				} else {
					ans[0][j][k] = 1e8;
				}
			}
		}
		for (int i=1; i<=p; i++) {
			for (int j=1; j<=n; j++) {
				for (int k=1; k<=n; k++) {
					ans[i][j][k] = min(ans[i-1][j][k], ans[i-1][j][ranks[i]]+ans[i-1][ranks[i]][k]);
				}
			}
		}
		int q;
		cin >> q;
		cout << "Case " << c << ": "; 
		int k, src, dest;
		for (int i=1; i<=q; i++) {
			cin >> k >> src >> dest;
			if (ans[k][src][dest] == 1e8) {
				cout << -1 << " ";
			} else {
				cout << ans[k][src][dest] << " ";
			}
		}
		cout << endl;
	}
}