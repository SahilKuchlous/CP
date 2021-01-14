#include <iostream>
#include <algorithm>
using namespace std;
int n, q;
bool org[1000000];
int lis[4000000], lds[4000000];
int c0[4000000], c1[4000000];
void merge (int x, int l, int r) {
	lis[x] = max(lis[2*x+1]+c1[2*x+2], c0[2*x+1]+lis[2*x+2]);
	lds[x] = max(lds[2*x+1]+c0[2*x+2], c1[2*x+1]+lds[2*x+2]);
	c0[x] = c0[2*x+1]+c0[2*x+2];
	c1[x] = c1[2*x+1]+c1[2*x+2];
}
void init (int x, int l, int r) {
	if (l == r) {
		lis[x] = lds[x] = 1;
		if (org[l]) {
			c1[x] = 1;
		} else {
			c0[x] = 1;
		}
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
	merge(x, l, r);
}
bool lazy[4000000];
void push (int x, int l, int r) {
	swap(lis[x], lds[x]);
	swap(c0[x], c1[x]);
	lazy[x] = 0;
	if (l != r) {
		lazy[2*x+1] = !lazy[2*x+1];
		lazy[2*x+2] = !lazy[2*x+2];
	}
}
void update (int x, int l, int r, int a, int b) {
	if (lazy[x]) push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] = 1;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b);
	update(2*x+2, m+1, r, a, b);
	merge(x, l, r);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	char ai;
	for (int i=0; i<n; i++) {
		cin >> ai;
		org[i] = (ai == '7');
	}
	init(0, 0, n-1);
	string ti;
	int li, ri;
	for (int i=0; i<q; i++) {
		cin >> ti;
		if (ti == "count") {
			cout << lis[0] << endl;
		} else {
			cin >> li >> ri;
			li--; ri--;
			update(0, 0, n-1, li, ri);
		}
	}
}