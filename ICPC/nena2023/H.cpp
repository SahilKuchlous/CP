#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	a--; b--;
	long long adj[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			adj[i][j] = 1e9;
		}
	}
	vector<long long> edges[m];
	for (int i=0; i<m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		s--; e--;
		adj[s][e] = adj[e][s] = w;
		edges[i] = {s, e, w};
	}
	long long dist[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			dist[i][j] = 1e9;
		}
	}
	for (int i=0; i<n; i++) {
		dist[i][i] = 0;
	}
	for (auto e: edges) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][e[0]]+dist[e[1]][j]+e[2]);
				dist[i][j] = min(dist[i][j], dist[i][e[1]]+dist[e[0]][j]+e[2]);
			}
		}
	}
	long long o = 0;
	for (auto e: edges) {
		long long min_dist = min(dist[a][e[0]]+dist[e[1]][b]+e[2], dist[a][e[1]]+dist[e[0]][b]+e[2]);
		if (min_dist == dist[a][b]) continue;
		o += e[2];
	}
	cout << o << endl;
}