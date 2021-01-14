#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Seg {
	int l, r;
	int s;
	Seg () {};
	Seg (int l, int r) : l(l), r(r) {};
	bool operator < (const Seg seg1) const {
		if (l != seg1.l) return l > seg1.l;
		return r < seg1.r;
	}
};
struct Node {
	Node *l, *r;
	int val;
	Node (int v) : l(nullptr), r(nullptr), val(v) {};
	Node (Node *l, Node *r) : l(l), r(r) {
		val = max(l->val, r->val);
	}
};
int n, q, k;
vector<Seg> segs;
Node* roots[300100];
Node* init (int l, int r) {
	if (l == r) {
		return new Node(1e9);
	}
	int m = (l+r)/2;
	return new Node(init(l, m), init(m+1, r));
}
Node* update (Node* v, int l, int r, int pos, int val) {
	if (l == r) {
		return new Node(val);
	}
	int m = (l+r)/2;
	if (pos <= m) {
		return new Node(update(v->l, l, m, pos, val), v->r);
	} else {
		return new Node(v->l, update(v->r, m+1, r, pos, val));
	}
}
int query (Node *v, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return -1;
	}
	if (a <= l && r <= b) {
		return v->val;
	}
	int m = (l+r)/2;
	int vl = query(v->l, l, m, a, b);
	int vr = query(v->r, m+1, r, a, b);
	return max(vl, vr);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> k;
	segs.resize(k);
	for (int i=0; i<k; i++) {
		cin >> segs[i].l >> segs[i].r >> segs[i].s;
		segs[i].l--; segs[i].r--; segs[i].s--;
	}
	sort(segs.begin(), segs.end());
	int cur[n];
	for (int i=0; i<n; i++) {
		cur[i] = 1e9;
	}
	roots[0] = init(0, n-1);
	for (int i=0; i<k; i++) {
		if (segs[i].r < cur[segs[i].s]) {
			if (n == 1) {
				roots[i+1] = new Node(segs[i].r);
			} else {
				roots[i+1] = update(new Node(roots[i]->l, roots[i]->r), 0, n-1, segs[i].s, segs[i].r);
			}
			cur[segs[i].s] = segs[i].r;
		} else {
			roots[i+1] = roots[i];
		}
	}
	int ai, bi, xi, yi;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi >> xi >> yi;
		ai--; bi--; xi--; yi--;
		int ind = lower_bound(segs.begin(), segs.end(), Seg(xi, 1e9))-segs.begin();
		Node* root = roots[ind];
		int o = query(root, 0, n-1, ai, bi);
		if (o <= yi) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}