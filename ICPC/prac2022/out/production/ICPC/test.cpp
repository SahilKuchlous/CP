#include <iostream>
using namespace std;
#define MAXN 100005

int segtree[4*MAXN];
int lazy[4*MAXN];

void push (int x, int l, int r) {
	segtree[x] += lazy[x];
	if (l == r) return;
	lazy[2*x+1] += lazy[x];
	lazy[2*x+2] += lazy[x];
	lazy[x] = 0;
}

void update (int x, int a, int b, int l, int r, amt) {
	push(x, a, b);
	if (r < a || b < l) return;
	if (l <= a && b <= r) {
		lazy[x] += amt;
		return;
	}
	if (a == b) return;
	int m = (a+b)/2;
	update(2*x+1, a, m, l, r, amt);
	update(2*x+2, m+1, b, l, r, amt);
	segtree[x] = segtree[2*x+1] + segtree[2*x+2];
}

int query (int x, int a, int b, int l, int r) {
	push(x, a, b);
	if (r < a || b < l) return 0;
	if (l <= a && b <= r) {
		return segtree[x];
	}
	int m = (l+r)/2;
	int retval = 0;
	retval += query(2*x+1, a, m, l, r);
	retval += query(2*x+2, m+1, b, l, r);
	return retval;
}

int main () {

}