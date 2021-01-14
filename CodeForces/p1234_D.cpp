#include <iostream>
#include <string>
using namespace std;

int seg[400000];
string s;
int n;

void create (int x, int l, int r) {
	if (l == r) {
		seg[x] = 1 << (s[l]-'a');
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	seg[x] = seg[2*x+1] | seg[2*x+2];
}

void update (int x, int l, int r, int y, int z) {
	if (r < y || l > y) {
		return;
	}
	if (l == y && r == y) {
		seg[x] = 1 << (z-'a');
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, y, z);
	update(2*x+2, m+1, r, y, z);
	seg[x] = seg[2*x+1] | seg[2*x+2];
}

int query (int x, int l, int r, int y, int z) {
	if (r<y || l>z) {
		return 0;
	}
	if (y <= l && r <= z) {
		return seg[x];
	}
	int m = (l+r)/2;
	int o1 = query(2*x+1, l, m, y, z);
	int o2 = query(2*x+2, m+1, r, y, z);
	return o1 | o2;
}

int main () {
	cin >> s;
	n = s.length();
	create(0, 0, n-1);
	int q;
	cin >> q;
	int t;
	int p, y, z;
	char c;
	for (int i=0; i<q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> p >> c;
			update(0, 0, n-1, p-1, c);
		} else {
			cin >> y >> z;
			int r = query(0, 0, n-1, y-1, z-1);
			int o = 0;
			for (int j=0; j<26; j++) {
				if (r & (1 << j)) {
					o++;
				}
			}
			cout << o << endl;
		}
	}
}