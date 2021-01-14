#include <iostream>
using namespace std;

int n, k;
int a[100001];
int seg[400000];

void create (int x, int l, int r) {
	if (l == r) {
		if (a[l] == 0) {
			seg[x] = -1;
		} else if (a[l] < 0) {
			seg[x] = 1;
		} else {
			seg[x] = 0;
		}
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	if (seg[2*x+1] == -1 || seg[2*x+2] == -1) {
		seg[x] = -1;
	} else {
		seg[x] = seg[2*x+1]+seg[2*x+2];
	}
}

void update (int x, int l, int r, int y, int z) {
	if (l > y || r < y) {
		return;
	}
	if (l == y && r == y) {
		if (z == 0) {
			seg[x] = -1;
		} else if (z < 0) {
			seg[x] = 1;
		} else {
			seg[x] = 0;
		}
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, y, z);
	update(2*x+2, m+1, r, y, z);
	if (seg[2*x+1] == -1 || seg[2*x+2] == -1) {
		seg[x] = -1;
	} else {
		seg[x] = seg[2*x+1]+seg[2*x+2];
	}
}

int query (int x, int l, int r, int y, int z) {
	if (z < l || y > r) {
		return 0;
	}
	if (y <= l && r <= z) {
		return seg[x];
	}
	int m = (l+r)/2;
	int c1 = query(2*x+1, l, m, y, z);
	int c2 = query(2*x+2, m+1, r, y, z);
	if (c1 == -1 || c2 == -1) {
		return -1;
	} else {
		return c1+c2;
	}
}

int main () {
	while (cin >> n >> k) {
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		create(0, 0, n-1);
		char t;
		int y, z, q;
		for (int i=0; i<k; i++) {
			cin >> t >> y >> z;
			if (t == 'C') {
				y--;
				update(0, 0, n-1, y, z);
			} else if (t == 'P') {
				y--;
				z--;
				q = query(0, 0, n-1, y, z);
				if (q == -1) {
					cout << 0;
				} else if (q%2 == 0) {
					cout << '+';
				} else {
					cout << '-';
				}
			}
		}
		cout << endl;
	}
}