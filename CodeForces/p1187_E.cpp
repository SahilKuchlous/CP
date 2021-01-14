#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> adj[200100];
int size[200100];
long long dp1[200100], dp2[200100];
void dfs (int x, int p) {
	size[x] = 1;
	long long best = 0;
	bool leaf = true;
	for (auto i: adj[x]) {
		if (i == p) continue;
		leaf = false;
		dfs(i, x);
		size[x] += size[i];
		dp2[x] += dp2[i];
		best = max(best, dp1[i]-dp2[i]+n-size[i]);
	}
	if (leaf) {
		dp1[x] = n;
		dp2[x] = 1;
		return;
	}
	dp1[x] += dp2[x]+best;
	dp2[x] += size[x];
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	cout << max(dp1[0], dp2[0]) << endl;
}