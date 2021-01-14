#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n, q;
vector<int> adj[MAXN];
int timer = 0;
int in_t[MAXN], out_t[MAXN];
int anc[MAXN][20];
void dfs (int x, int p) {
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
bool is_anc (int x, int y) {
	return (in_t[x] <= in_t[y] && out_t[y] <= out_t[x]);
}
int dist (int x, int y) {
	if (is_anc(x, y)) return 0;
	int d = 0;
	int cur = x;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[cur][i], y)) {
			cur = anc[cur][i];
			d += (1<<i);
		}
	}
	d++;
	return d;
}
int find (int x, int d) {
	int cur = x;
	for (int i=19; i>=0; i--) {
		if ((1<<i) <= d) {
			cur = anc[cur][i];
			d -= (1<<i);
		}
	}
	return cur;
}
int calc (int x, int y, int d) {
	int dx = dist(x, y);
	if (dx >= d) return find(x, d);
	d -= dx;
	int dy = dist(y, x);
	if (d < dy) return find(y, dy-d);
	return y;
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
	dfs(0, 0);
	int q;
	cin >> q;
	int ci;
	while (q--) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		cout << calc(ai, bi, ci)+1 << '\n';
	}
}