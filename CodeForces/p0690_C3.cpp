#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
int n;
vector<int> adj[MAXN];
int depth[MAXN];
int timer = 0;
int in_t[MAXN], out_t[MAXN];
int anc[MAXN][20];
void dfs (int x, int p) {
	depth[x] = depth[p]+1;
	in_t[x] = timer++;
	anc[x][0] = p;
	for (int i=1; i<20; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
	out_t[x] = timer;
}
bool is_anc (int a, int b) {
	return (in_t[a] <= in_t[b] && out_t[b] <= out_t[a]);
}
int lca (int a, int b) {
	if (is_anc(a, b)) return a;
	if (is_anc(b, a)) return b;
	int cur = a;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[cur][i], b)) cur = anc[cur][i];
	}
	return anc[cur][0];
}
int dist (int a, int b) {
	int l = lca(a, b);
	return depth[a]+depth[b]-2*depth[l];
}
int e1, e2;
int main () {
	cin >> n;
	int pi;
	for (int i=1; i<n; i++) {
		cin >> pi;
		pi--;
		adj[i].push_back(pi);
		adj[pi].push_back(i);
	}
	depth[0] = 0;
	dfs(0, 0);
	e1 = e2 = 0;
	for (int i=1; i<n; i++) {
		int cur = dist(e1, e2);
		int d1 = dist(i, e1);
		if (d1 > cur) {
			cout << d1 << " ";
			e2 = i;
			continue;
		}
		int d2 = dist(i, e2);
		if (d2 > cur) {
			cout << d2 << " ";
			e1 = i;
			continue;
		}
		cout << cur << " ";
	}
	cout << endl;
}