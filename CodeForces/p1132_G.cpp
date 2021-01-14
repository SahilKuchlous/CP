#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define MAXN 1000005
int n, k;
int a[MAXN];
stack<int> cur;
int nxt[MAXN];
vector<int> adj[MAXN];
int in_t[MAXN], out_t[MAXN];
int timer = 0;
void dfs (int x, int p) {
	in_t[x] = timer++;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
	out_t[x] = timer-1;
}
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
		lazy[x] = v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=n-1; i>=0; i--) {
		while (cur.size() > 0 && a[cur.top()] <= a[i]) {
			cur.pop();
		}
		nxt[i] = (cur.size() > 0 ? cur.top():n);
		cur.push(i);
	}
	for (int i=0; i<n; i++) {
		adj[i].push_back(nxt[i]);
		adj[nxt[i]].push_back(i);
	}
	dfs(n, -1);
	for (int i=0; i<k; i++) {
		update(0, 0, n, in_t[i], out_t[i], 1);
	}
	cout << segtree[0] << " ";
	for (int i=0; i<n-k; i++) {
		update(0, 0, n, in_t[i], out_t[i], -1);
		update(0, 0, n, in_t[i+k], out_t[i+k], 1);
		cout << segtree[0] << " ";
	}
	cout << endl;
}