#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n, m, q;
vector< pair<int, int> > adj[MAXN];
int timer = 0;
int in_t[MAXN], out_t[MAXN];
int anc[MAXN][20];
int min_e[MAXN][20];
void dfs (int x, int p) {
	in_t[x] = timer++;
	anc[x][0] = p;
	for (int i=1; i<20; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
		min_e[x][i] = min(min_e[x][i-1], min_e[anc[x][i-1]][i-1]);
	}
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		min_e[i.first][0] = i.second;
		dfs(i.first, x);
	}
	out_t[x] = timer;
}
bool is_anc (int x, int y) {
	return (in_t[x] <= in_t[y] && out_t[y] <= out_t[x]);
}
int calc (int x, int y) {
	if (is_anc(x, y)) return 1e9;
	int o = 1e9;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[x][i], y)) {
			o = min(o, min_e[x][i]);
			x = anc[x][i];
		}
	}
	o = min(o, min_e[x][0]);
	return o;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(ai, ci));
	}
	min_e[0][0] = 1e9;
	dfs(0, 0);
	int q;
	cin >> q;
	while (q--) {
		cin >> ai >> bi;
		ai--; bi--;
		cout << min(calc(ai, bi), calc(bi, ai)) << '\n';
	}
}