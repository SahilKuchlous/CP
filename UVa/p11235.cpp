#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector< vector< vector<int> > > seg (400000, vector< vector<int> > (3, vector<int>(2)) );
int a[100001];
int n, q;
void create (int x, int l, int r) {
	if (l == r) {
		seg[x][0][0] = 1;
		seg[x][1][0] = 1;
		seg[x][2][0] = 1;
		seg[x][0][1] = a[l];
		seg[x][1][1] = a[l];
		seg[x][2][1] = a[l];
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	if (seg[2*x+1][2][1] == seg[2*x+2][1][1]) {
		if (seg[2*x+1][2][0]+seg[2*x+2][1][0] > seg[2*x+1][0][0] && seg[2*x+1][2][0]+seg[2*x+2][1][0] > seg[2*x+2][0][0]) {
			seg[x][0][0] = seg[2*x+1][2][0]+seg[2*x+2][1][0];
			seg[x][0][1] = seg[2*x+1][2][1];
		} else {
			if (seg[2*x+1][0][0] > seg[2*x+2][0][0]) {
				seg[x][0][0] = seg[2*x+1][0][0];
				seg[x][0][1] = seg[2*x+1][0][1];
			} else {
				seg[x][0][0] = seg[2*x+2][0][0];
				seg[x][0][1] = seg[2*x+2][0][1];
			}
		}
	} else {
		if (seg[2*x+1][0][0] > seg[2*x+2][0][0]) {
			seg[x][0][0] = seg[2*x+1][0][0];
			seg[x][0][1] = seg[2*x+1][0][1];
		} else {
			seg[x][0][0] = seg[2*x+2][0][0];
			seg[x][0][1] = seg[2*x+2][0][1];
		}
	}
	if (seg[2*x+1][1][1] == seg[2*x+2][1][1]) {
		seg[x][1][0] = seg[2*x+1][1][0] + seg[2*x+2][1][0];
	} else {
		seg[x][1][0] = seg[2*x+1][1][0];
	}
	seg[x][1][1] = seg[2*x+1][1][1];
	if (seg[2*x+2][2][1] == seg[2*x+1][2][1]) {
		seg[x][2][0] = seg[2*x+2][2][0] + seg[2*x+1][2][0];
	} else {
		seg[x][2][0] = seg[2*x+2][2][0];
	}
	seg[x][2][1] = seg[2*x+2][2][1];
	if (seg[x][1][0] > seg[x][0][0]) {
		seg[x][0][0] = seg[x][1][0];
		seg[x][0][1] = seg[x][1][1];
	}
	if (seg[x][2][0] > seg[x][0][0]) {
		seg[x][0][0] = seg[x][2][0];
		seg[x][0][1] = seg[x][2][1];
	}
}
vector< vector<int> > query (int x, int l, int r, int y, int z) {
	vector< vector<int> > o(3, vector<int>(2));
	if (l>z || r<y) {
		o[0][0] = -1;
		return o;
	}
	if (y<=l && r<=z) {
		return seg[x];
	}
	int m = (l+r)/2;
	vector< vector<int> > s1 = query(2*x+1, l, m, y, z);
	vector< vector<int> > s2 = query(2*x+2, m+1, r, y, z);
	if (s1[0][0] == -1) {
		return s2;
	}
	if (s2[0][0] == -1) {
		return s1;
	}
	if (s1[2][1] == s2[1][1]) {
		if (s1[2][0]+s2[1][0] > s1[0][0] && s1[2][0]+s2[1][0] > s2[0][0]) {
			o[0][0] = s1[2][0]+s2[1][0];
			o[0][1] = s1[2][1];
		} else {
			if (s1[0][0] > s2[0][0]) {
				o[0][0] = s1[0][0];
				o[0][1] = s1[0][1];
			} else {
				o[0][0] = s2[0][0];
				o[0][1] = s2[0][1];
			}
		}
	} else {
		if (s1[0][0] > s2[0][0]) {
			o[0][0] = s1[0][0];
			o[0][1] = s1[0][1];
		} else {
			o[0][0] = s2[0][0];
			o[0][1] = s2[0][1];
		}
	}
	if (s1[1][1] == s2[1][1]) {
		o[1][0] = s1[1][0] + s2[1][0];
	} else {
		o[1][0] = s1[1][0];
	}
	o[1][1] = s1[1][1];
	if (s2[2][1] == s1[2][1]) {
		o[2][0] = s2[2][0] + s1[2][0];
	} else {
		o[2][0] = s2[2][0];
	}
	o[2][1] = s2[2][1];
	if (o[1][0] > o[0][0]) {
		o[0][0] = o[1][0];
		o[0][1] = o[1][1];
	}
	if (o[2][0] > o[0][0]) {
		o[0][0] = o[2][0];
		o[0][1] = o[2][1];
	}
	return o;
}
int main () {
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> q;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		create(0, 0, n-1);
		/*
		for (int i=0; i<2*n; i++) {
			cout << seg[i][0][0] << " " << seg[i][0][1] << "; " << seg[i][1][0] << " " << seg[i][1][1] << "; " << seg[i][2][0] << " " << seg[i][2][1] << endl;
		}
		*/
		int y, z;
		for (int i=0; i<q; i++) {
			cin >> y >> z;
			y--;
			z--;
			vector< vector<int> > o = query(0, 0, n-1, y, z);
			// cout << o[0][0] << " " << o[0][1] << "; " << o[1][0] << " " << o[1][1] << "; " << o[2][0] << " " << o[2][1] << endl;
			cout << o[0][0] << endl;
		}
	}
}