#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
string seq;
int n;
int segtree[4000000][3];
void build (int x, int l, int r) {
	if (l == r) {
		segtree[x][0] = segtree[x][1] = segtree[x][2] = 0;
		if (seq.at(l) == '(') {
			segtree[x][1]++;
		} else {
			segtree[x][2]++;
		}
		return;
	}
	int m = (l+r)/2;
	build(2*x+1, l, m);
	build(2*x+2, m+1, r);
	segtree[x][0] = segtree[2*x+1][0]+segtree[2*x+2][0];
	int ext = min(segtree[2*x+1][1], segtree[2*x+2][2]);
	segtree[x][0] += 2*ext;
	segtree[x][1] = segtree[2*x+1][1]+segtree[2*x+2][1]-ext;
	segtree[x][2] = segtree[2*x+1][2]+segtree[2*x+2][2]-ext;
}
vector<int> query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) {
		return {0, 0, 0};
	}
	if (a <= l && r <= b) {
		return {segtree[x][0], segtree[x][1], segtree[x][2]};
	}
	int m = (l+r)/2;
	vector<int> p1 = query(2*x+1, l, m, a, b);
	vector<int> p2 = query(2*x+2, m+1, r, a, b);
	vector<int> ret = {0, 0, 0};
	ret[0] = p1[0]+p2[0];
	int ext = min(p1[1], p2[2]);
	ret[0] += 2*ext;
	ret[1] = p1[1]+p2[1]-ext;
	ret[2] = p1[2]+p2[2]-ext;
	return ret;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> seq;
	n = seq.length();
	build(0, 0, n-1);
	int q;
	cin >> q;
	int ai, bi;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi;
		ai--;
		bi--;
		cout << query(0, 0, n-1, ai, bi)[0] << endl;
	}
}