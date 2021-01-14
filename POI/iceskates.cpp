#include <iostream>
using namespace std;
int n, m, k, d;
struct node {
	long long best, pre, suf, ttl; 
};
node segtree[800000];
void merge (int x) {
	segtree[x].best = max(max(segtree[2*x+1].best, segtree[2*x+2].best), segtree[2*x+1].suf+segtree[2*x+2].pre);
	segtree[x].pre = max(segtree[2*x+1].pre, segtree[2*x+1].ttl+segtree[2*x+2].pre);
	segtree[x].suf = max(segtree[2*x+2].suf, segtree[2*x+2].ttl+segtree[2*x+1].suf);
	segtree[x].ttl = segtree[2*x+1].ttl + segtree[2*x+2].ttl;
}
void init (int x, int l, int r) {
	if (l == r) {
		segtree[x] = {-k, -k, -k, -k};
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
	merge(x);
}
void update (int x, int l, int r, int p, int v) {
	if (p < l || r < p) return;
	if (l == r) {
		segtree[x].best += v;
		segtree[x].pre += v;
		segtree[x].suf += v;
		segtree[x].ttl += v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	merge(x);
}
int main () {
	cin >> n >> m >> k >> d;
	init(0, 0, n-1);
	long long lim = 1ll*k*d;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--;
		update(0, 0, n-1, ai, bi);
		cout << (segtree[0].best <= lim ? "TAK":"NIE") << endl;
	}
}