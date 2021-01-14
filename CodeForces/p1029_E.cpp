#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> adj[200100];
long long dp1[200100]; // I am marked
long long dp2[200100]; // One of my children is marked
long long dp3[200100]; // Parent is marked
void dfs (int x, int p) {
	if (p != 0) dp1[x] = 1;
	long long best = 1e6;
	long long ttl = 0;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		dp1[x] += min(dp1[i], min(dp2[i], dp3[i]));
		best = min(best, max(dp1[i], dp2[i])-dp2[i]);
		ttl += min(dp1[i], dp2[i]);
		dp3[x] += min(dp1[i], dp2[i]); 
	}
	dp2[x] = ttl+best;
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
	cout << min(dp1[0], min(dp2[0], dp3[0])) << endl;
}