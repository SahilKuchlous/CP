#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
#define MOD 100000007
int n;
vector<int> adj[MAXN];
long long dp1[MAXN], dp2[MAXN];
void dfs (int x, int p) {
	dp1[x] = 1;
	dp2[x] = 0;
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
}