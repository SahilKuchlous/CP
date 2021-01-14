#include <iostream>
using namespace std;
void update (int tree[], int n, int p, int q, int v, int l, int r, int lazy[]) {
	if (lazy[n] != 0) {
		if (l==r) {
			tree[n] += lazy[n];
			lazy[n] = 0;
		} else {
			tree[n] += lazy[n] * (r-l+1);
			lazy[2*n+1] += lazy[n];
			lazy[2*n+2] += lazy[n];
			lazy[n] = 0;
		}
	}
	if (r<p || l>q) {
		return;
	}
	if (l>=p && r<=q) {
		lazy[n] += v;
		return;
	}
	int m = (r+l)/2;
	update(tree, 2*n+1, p, q, v, l, m, lazy);
	update(tree, 2*n+2, p, q, v, m+1, r, lazy);
}
int query (int tree[], int n, int p, int q, int l, int r, int lazy[]) {
	if (lazy[n] != 0) {
		if (l==r) {
			tree[n] += lazy[n];
			lazy[n] = 0;
		} else {
			tree[n] += lazy[n] * (r-l+1);
			lazy[2*n+1] += lazy[n];
			lazy[2*n+2] += lazy[n];
			lazy[n] = 0;
		}
	}
	if (r<p || l>q) {
		return 0;
	}
	if (l>=p && r<=q) {
		return tree[n];
	}
	int t = tree[n];
	int m = (r+l)/2;
	t += query(tree, 2*n+1, p, q, l, m, lazy);
	t += query(tree, 2*n+2, p, q, m+1, r, lazy);
	return t;
}
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n, c, t, p, q, v;
		cin >> n >> c;
		int tree[4*n];
		int lazy[4*n];
		for (int i=0; i<4*n; i++) {
			tree[i] = 0;
			lazy[i] = 0;
		}
		for (int i=0; i<c; i++) {
			cin >> t;
			if (t == 0) {
				cin >> p >> q >> v;
				p--;
				q--;
				update(tree, 0, p, q, v, 0, n-1, lazy);
				for (int i=0; i<4*n; i++) {
					cout << lazy[i] << " ";
				}
				cout << endl;
			} else {
				cin >> p >> q;
				p--;
				q--;
				cout << query(tree, 0, p, q, 0, n-1, lazy) << endl;
				for (int i=0; i<4*n; i++) {
					cout << tree[i] << " ";
				}
				cout << endl;
			}
		}
	}
}