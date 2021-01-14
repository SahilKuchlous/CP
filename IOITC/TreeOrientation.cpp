#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
#define MOD 1000000007
long long bin[35];
long long pow2 (int x) {
	long long o = 1;
	for (int i=0; i<35; i++) {
		if (x & (1ll<<i)) o = o*bin[i] % MOD;
	}
	return o;
}
int n, m;
vector<int> adj[MAXN];
int in_t[MAXN], out_t[MAXN];
int timer = 0;
int anc[MAXN][20];
void dfs1 (int x, int p) {
	in_t[x] = timer++;
	anc[x][0] = p;
	for (int i=1; i<20; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
	}
	out_t[x] = timer;
}
bool is_anc (int a, int b) {
	return (in_t[a] <= in_t[b] && out_t[b] <= out_t[a]);
}
int lca (int a, int b) {
	if (is_anc(a, b)) return a;
	if (is_anc(b, a)) return b;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[a][i], b)) a = anc[a][i];
	}
	return anc[a][0];
}
int c1[MAXN], c2[MAXN];
int empty = 0;
int disc = 0;
int dfs2 (int x, int p) {
	int cur = 0;
	for (auto i: adj[x]) {
		if (i == p) continue;
		cur += dfs2(i, x);
	}
	cur -= c2[x];
	if (cur == 0 && c1[x] > 0) disc++;
	if (cur > 0) disc -= c2[x];
	cur += c1[x];
	if (cur == 0 && x != p) empty++;
	return cur;
}
int main () {
	bin[0] = 2;
	for (int i=1; i<35; i++) {
		bin[i] = bin[i-1]*bin[i-1] % MOD;
	}
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs1(0, 0);
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		int l = lca(ai, bi);
		c1[ai]++;
		c1[bi]++;
		c2[l] += 2;
		if (ai == l) {
			c1[ai]--; c1[bi]++;
		}
		if (bi == l) {
			c1[bi]--; c1[ai]++;
		}
	}
	dfs2(0, 0);
	cout << empty << " " << disc << endl;
	cout << pow2(empty+disc) << endl;
}