#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, k;
map< int, vector<int> > adj;
int dp[100][100];

void dfs (int v, int p) {
	dp[v][1] = 1;
	for (int ic=0; ic<adj[v].size(); ic++) {
		int i = adj[v][ic];
		if (i != p) {
			dfs(i, v);
			for (int x=1; x<k; x++) {
				dp[v][x+1] += dp[i][x];
				for (int jc=0; jc<ic; jc++) {
					int j = adj[v][jc];
					if (j != p) {
						for (int y=1; y<k-x; y++) {
							dp[v][x+y+1] += dp[i][x]*dp[j][y];
						}
					}
				}
			}
		}
	}
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		k++;
		adj.clear();
		int a, b;
		for (int i=0; i<n-1; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<=k; j++) {
				dp[i][j] = 0;
			}
		}
		dfs(0, -1);
		int o = 0;
		for (int i=0; i<n; i++) {
			for (int j=1; j<=k; j++) {
				cout << dp[i][j] << " ";
				o += dp[i][j];
			}
			cout << endl;
		}
		cout << o << endl;
	}
}