#include <iostream>
#include <string>
using namespace std;

int n;
int seg[4000000];
int lazy[4000000];
int a[1024000];

void create (int x, int l, int r) {
	if (l == r) {
		seg[x] = a[l];
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	seg[x] = seg[2*x+1]+seg[2*x+2];
}

void update (int x, int l, int r, int y, int z, int t) {
	int m = (l+r)/2;
	if (lazy[x] != -1) {
		if (lazy[x] == 0) {
			seg[x] = r-l+1;
		} else if (lazy[x] == 1) {
			seg[x] = 0;
		} else if (lazy[x] == 2) {
			seg[x] = r-l+1 - seg[x];
		}
		if (l != r) {
			if (lazy[2*x+1] == 0 && lazy[x] == 2) {
				lazy[2*x+1] = 1;
			} else if (lazy[2*x+1] == 1 && lazy[x] == 2) {
				lazy[2*x+1] = 0;
			} else if (lazy[2*x+1] == 2 && lazy[x] == 2) {
				lazy[2*x+1] = -1;
			} else {
				lazy[2*x+1] = lazy[x];
			}
			if (lazy[2*x+2] == 0 && lazy[x] == 2) {
				lazy[2*x+2] = 1;
			} else if (lazy[2*x+2] == 1 && lazy[x] == 2) {
				lazy[2*x+2] = 0;
			} else if (lazy[2*x+2] == 2 && lazy[x] == 2) {
				lazy[2*x+2] = -1;
			} 
			else {
				lazy[2*x+2] = lazy[x];
			}
		}
		lazy[x] = -1;
	}
	if (r<y || l>z) {
		return;
	}
	if (y<=l && r<=z) {
		if (t == 0) {
			seg[x] = r-l+1;
		} else if (t == 1) {
			seg[x] = 0;
		} else if (t == 2) {
			seg[x] = r-l+1 - seg[x];
		}
		if (l != r) {
			if (lazy[2*x+1] == 0 && t == 2) {
				lazy[2*x+1] = 1;
			} else if (lazy[2*x+1] == 1 && t == 2) {
				lazy[2*x+1] = 0;
			} else if (lazy[2*x+1] == 2 && t == 2) {
				lazy[2*x+1] = -1;
			} else {
				lazy[2*x+1] = t;
			}
			if (lazy[2*x+2] == 0 && t == 2) {
				lazy[2*x+2] = 1;
			} else if (lazy[2*x+2] == 1 && t == 2) {
				lazy[2*x+2] = 0;
			} else if (lazy[2*x+2] == 2 && t == 2) {
				lazy[2*x+2] = -1;
			} else {
				lazy[2*x+2] = t;
			}
		}
		return;
	}
	update(2*x+1, l, m, y, z, t);
	update(2*x+2, m+1, r, y, z, t);
	seg[x] = seg[2*x+1]+seg[2*x+2];
}

int query (int x, int l, int r, int y, int z) {
	int m = (l+r)/2;
	if (lazy[x] != -1) {
		if (lazy[x] == 0) {
			seg[x] = r-l+1;
		} else if (lazy[x] == 1) {
			seg[x] = 0;
		} else if (lazy[x] == 2) {
			seg[x] = r-l+1 - seg[x];
		}
		if (l != r) {
			if (lazy[2*x+1] == 0 && lazy[x] == 2) {
				lazy[2*x+1] = 1;
			} else if (lazy[2*x+1] == 1 && lazy[x] == 2) {
				lazy[2*x+1] = 0;
			} else if (lazy[2*x+1] == 2 && lazy[x] == 2) {
				lazy[2*x+1] = -1;
			} else {
				lazy[2*x+1] = lazy[x];
			}
			if (lazy[2*x+2] == 0 && lazy[x] == 2) {
				lazy[2*x+2] = 1;
			} else if (lazy[2*x+2] == 1 && lazy[x] == 2) {
				lazy[2*x+2] = 0;
			} else if (lazy[2*x+2] == 2 && lazy[x] == 2) {
				lazy[2*x+2] = -1;
			} 
			else {
				lazy[2*x+2] = lazy[x];
			}
		}
		lazy[x] = -1;
	}
	if (r<y || l>z) {
		return 0;
	}
	if (y<=l && r<=z) {
		return seg[x];
	}
	int o = 0;
	o += query(2*x+1, l, m, y, z);
	o += query(2*x+2, m+1, r, y, z);
	return o;
}

int main () {
	int t;
	cin >> t;
	for (int r=1; r<=t; r++) {
		cout << "Case " << r << ":" << endl; 
		n = 0;
		int m;
		cin >> m;
		int t;
		string s;
		int x = 0;
		for (int i=0; i<m; i++) {
			cin >> t >> s;
			n += t*s.size();
			for (int j=0; j<t; j++) {
				for (auto k: s) {
					a[x] = k-'0';
					x++;
				}
			}
		}
		create(0, 0, n-1);
		for (int i=0; i<4*n; i++) {
			lazy[i] = -1;
		}
		int q;
		cin >> q;
		char c;
		int y, z;
		int o = 1;
		for (int i=0; i<q; i++) {
			cin >> c >> y >> z;
			if (c == 'F') {
				update(0, 0, n-1, y, z, 0);
			} else if (c == 'E') {
				update(0, 0, n-1, y, z, 1);
			} else if (c == 'I') {
				update(0, 0, n-1, y, z, 2);
			} else if (c == 'S') {
				cout << "Q" << o << ": " << query(0, 0, n-1, y, z) << endl;
				/*
				for (int i=0; i<2*n; i++) {
					cout << seg[i] << " ";
				}
				cout << endl;
				*/
				o++;
			}
		}
	}
}