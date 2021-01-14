#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int color[300100];
vector<int> adj[300100];
long long dp[300100][40];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> color[i];
		color[i]--;
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	long long o = 0;
	for (int i=0; i<(1<<k); i++) {
		for (int x=0; x<n; x++) {
			if ((i & (1<<color[x])) == 0) continue;
			if (i == (1<<color[x])) dp[x][i]++;
			for (auto y: adj[x]) {
				dp[x][i] += dp[y][i-(1<<color[x])];
				o += dp[y][i-(1<<color[x])];
			}
		}
	}
	cout << o << endl;
}