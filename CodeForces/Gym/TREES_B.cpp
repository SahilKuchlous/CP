#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n;
vector<int> adj[MAXN];
int dist[MAXN];
bool diam[MAXN];
void dfs (int x, int p) {
	dist[x] = dist[p]+1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dist[0] = 0;
	dfs(0, 0);
	int e1 = 0;
	for (int i=0; i<n; i++) {
		if (dist[i] > dist[e1]) e1 = i;
	}
	dist[e1] = 0;
	dfs(e1, e1);
	int e2 = 0;
	for (int i=0; i<n; i++) {
		if (dist[i] > dist[e2]) e2 = i;
	}
	int len = dist[e2];
	for (int i=0; i<n; i++) {
		if (dist[i] == len) diam[i] = true;
	}
	dist[e2] = 0;
	dfs(e2, e2);
	for (int i=0; i<n; i++) {
		if (dist[i] == len) diam[i] = true;
	}
	len--;
	for (int i=0; i<n; i++) {
		cout << len+diam[i] << '\n';
	}
}