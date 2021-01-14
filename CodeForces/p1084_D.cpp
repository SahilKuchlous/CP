#include <iostream>
#include <vector>
using namespace std;
int n;
int val[300100];
vector< pair<int, int> > adj[300100];
long long dp[300100];
long long o = 0;
void dfs (int x, int p) {
	long long h1 = 0, h2 = 0;
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs(i.first, x);
			if (dp[i.first]-i.second > h1) {
				h2 = h1;
				h1 = dp[i.first]-i.second;
			} else if (dp[i.first]-i.second > h2) {
				h2 = dp[i.first]-i.second;
			}
		}
	}
	o = max(o, h1+h2+val[x]);
	dp[x] = h1+val[x];
}
int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> val[i];
	}
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi >> ci;
		adj[ai].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(ai, ci));
	}
	dfs(1, 1);
	cout << o << endl;
}