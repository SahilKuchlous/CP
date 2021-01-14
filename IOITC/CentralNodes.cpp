#include <iostream>
#include <set>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long adj[n][n];
	int req[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			adj[i][j] = 1e16;
			req[i][j] = -1;
		}
	}
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai][bi] = adj[bi][ai] = ci;
	}
	for (int mid=0; mid<n; mid++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i == j) continue;
				if (adj[i][j] > adj[i][mid]+adj[mid][j]) {
					adj[i][j] = adj[i][mid]+adj[mid][j];
					req[i][j] = mid;
				} else if (adj[i][j] == adj[i][mid]+adj[mid][j]) {
					req[i][j] = -1;
				}
			}
		}
	}
	set<int> o;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (req[i][j] > -1) {
				o.insert(req[i][j]);
			}
		}
	}
	cout << o.size() << endl;
	for (auto i: o) cout << i+1 << " ";
	cout << endl;
	return 0;
}