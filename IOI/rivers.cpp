#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, k;
int wt[n];
vector< pair<int, int> > adj[101];
long long dp[101][101][101];
vector<int> hist;
int total[101];
int pos[101];
multiset<int> opts;
void dfs (int x, int p) {
	total[x] = wt[x];
	for (auto i: adj[x]) {
		if (i.first != p) {
			hist.push_back(i.second);
			dfs(i.first, x);
			hist.pop_back();
			total[x] += total[i.first];
		}
	}
	int dist = 0;
	for (int i=0; i<=n; i++) {
		if (i == hist.size()) break;
		dist += hist[hist.size()-i-1];
	}
}
int main () {
	cin >> n >> k;
	int ai, bi, ci;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi >> ci;
		wt[i] = ai;
		adj[i+1].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(i+1, ci));
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			for (int c=0; c<=k; c++) {
				dp[i][j][c] = 1e8;
			}
		}
	}
	dfs(0, 0);
}