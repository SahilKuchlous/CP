#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
int n;
vector<int> adj[100100];
long long dp1[100100], dp2[100100];
void dfs (int x, int p) {
	dp1[x] = dp2[x] = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		dp1[x] = (dp1[x]*dp2[i])%MOD;
		dp2[x] = (dp2[x]*(dp1[i]+dp2[i])%MOD)%MOD;
	}
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
	cout << (dp1[0]+dp2[0])%MOD << endl;
}