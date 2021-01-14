#include <iostream>
using namespace std;
int n;
int val[300100];
int pos[300100];
int bombs[300100];
int segtree[2000100];
int lazy[2000100];
void push (int x, int l, int r) {
	if (lazy[x] != 0) {
		segtree[x] += lazy[x];
		if (l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	}
}
void update (int x, int l, int r, int a, int b, int v) {
	push(x, l, r);
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[x] += v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> val[i];
		pos[val[i]] = i;
	}
	for (int i=0; i<n; i++) {
		cin >> bombs[i];
		bombs[i]--;
	}
	int cur = n+1;
	for (int i=0; i<n; i++) {
		while (segtree[0] <= 0) {
			cur--;
			update(0, 0, n-1, 0, pos[cur], 1);
		}
		cout << cur << " ";
		update(0, 0, n-1, 0, bombs[i], -1);
	}
	cout << endl;
}