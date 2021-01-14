#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
ifstream fin("barnpainting.in");
ofstream fout("barnpainting.out");
int n, k;
map< int, vector<int> > adj;
int col[100100];
long long dp[100100][4];
void dfs (int v, int p) {
	if (col[v] == 0) {
		dp[v][1] = dp[v][2] = dp[v][3] = 1;
	} else {
		dp[v][1] = dp[v][2] = dp[v][3] = 0;
		dp[v][col[v]] = 1;
	}
	for (auto i: adj[v]) {
		if (i != p) {
			dfs(i, v);
			dp[v][1] *= dp[i][2]+dp[i][3];
			dp[v][1] %= 1000000007;
			dp[v][2] *= dp[i][1]+dp[i][3];
			dp[v][2] %= 1000000007;
			dp[v][3] *= dp[i][1]+dp[i][2];
			dp[v][3] %= 1000000007;
		}
	}
}
int main () {
	fin >> n >> k;
	int x, y;
	for (int i=0; i<n-1; i++) {
		fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=0; i<=n; i++) {
		col[i] = 0;
	}
	int b, c;
	for (int i=0; i<k; i++) {
		fin >> b >> c;
		col[b] = c;
	}
	dfs(1, 0);
	long long o = ((dp[1][1]+dp[1][2]+dp[1][3]) % 1000000007);
	fout << o << endl;
}