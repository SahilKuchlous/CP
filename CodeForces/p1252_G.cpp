#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n, m, q;
int org[MAXN];
vector<int> rep[MAXN];
int pos[MAXN];
int segtree[4*MAXN];
int lazy[4*MAXN];
void push (int x, int l, int r) {
	if (lazy[x] == 0) return;
	segtree[x] += lazy[x];
	if (l != r) {
		lazy[2*x+1] += lazy[x];
		lazy[2*x+2] += lazy[x];
	}
	lazy[x] = 0;
}
void update (int x, int l, int r, int a, int b, int v) {
	push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] += v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		cin >> org[i];
	}
	pos[0] = 0;
	for (int i=1; i<n; i++) {
		if (org[i] < org[0]) pos[0]++;
	}
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		pos[i+1] = pos[i];
		cin >> ai;
		update(0, 0, m-1, i, i, pos[i]-ai);
		while (ai--) {
			cin >> bi;
			rep[i].push_back(bi);
			if (bi > org[0]) pos[i+1]--;
		}
	}
	for (int i=0; i<q; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		if (rep[ai][bi] < org[0] && ci > org[0]) {
			if (ai < m-1) update(0, 0, m-1, ai+1, m-1, -1);
		} else if (rep[ai][bi] > org[0] && ci < org[0]) {
			if (ai < m-1) update(0, 0, m-1, ai+1, m-1, 1);
		}
		rep[ai][bi] = ci;
		cout << (segtree[0] >= 0) << '\n';
	}
}