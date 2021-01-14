#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, l;
		cin >> n >> m >> l;
		int path[l];
		for (int i=0; i<l; i++) {
			cin >> path[i];
			path[i]--;
		}
		long long dist[n][n];
		long long org[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i == j) {
					dist[i][j] = org[i][j] = 0;
				} else {
					dist[i][j] = org[i][j] = 1e12;
				}
			}
		}
		int ai, bi, ci;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi >> ci;
			ai--;
			bi--;
			dist[ai][bi] = dist[bi][ai] = ci;
			org[ai][bi] = org[bi][ai] = ci;
		}
		for (int z=0; z<n; z++) {
			for (int x=0; x<n; x++) {
				for (int y=0; y<n; y++) {
					dist[x][y] = min(dist[x][y], dist[x][z]+dist[z][y]);
				}
			}
		}
		/*
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
		*/
		int start = path[0];
		int length = 0;
		int o = 1;
		bool pos = true;
		for (int i=1; i<l; i++) {
			if (org[path[i-1]][path[i]] > dist[path[i-1]][path[i]]) {
				pos = false;
				break;
			}
			length += org[path[i-1]][path[i]];
			if (length > dist[start][path[i]]) {
				start = path[i-1];
				length = org[path[i-1]][path[i]];
				o++;
			}
		}
		if (!pos) {
			cout << -1 << endl;
		} else {
			cout << o+1 << endl;
		}
	}
}