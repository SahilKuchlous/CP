#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct range {
	int id;
	int l, r;
	bool operator < (const range a) const {
		return l < a.l;
	}
};
range ranges[200100];
range sor_r[200100];
pair<int, int> segtree[800100];
void update (int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		segtree[x] = make_pair(v, l);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	if (segtree[2*x+1].first > segtree[x].first) segtree[x] = segtree[2*x+1];
	update(2*x+2, m+1, r, p, v);
	if (segtree[2*x+2].first > segtree[x].first) segtree[x] = segtree[2*x+2];
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return make_pair(-1, -1);
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	pair<int, int> o = make_pair(-1, -1);
	pair<int, int> r1 = query(2*x+1, l, m, a, b);
	if (r1.first > o.first) o = r1;
	pair<int, int> r2 = query(2*x+2, m+1, r, a, b);
	if (r2.first > o.first) o = r2;
	return o;
}
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		ranges[i].id = sor_r[i].id = i;
		cin >> ranges[i].l >> ranges[i].r;
		ranges[i].l--; ranges[i].r--;
		sor_r[i].l = ranges[i].l;
		sor_r[i].r = ranges[i].r;
	}
	sort(sor_r, sor_r+n);
	int cur_i = 0;
	set< pair<int, int> > cur;
	int val[n];
	int loc[n];
	for (int i=0; i<n; i++) {
		while (cur_i < n && sor_r[cur_i].l == i) {
			cur.insert(make_pair(sor_r[cur_i].r, sor_r[cur_i].id));
			cur_i++;
		}
		val[cur.begin()->second] = i;
		loc[i] = cur.begin()->second;
		cur.erase(cur.begin());
	}
	int swp_a = -1, swp_b = -1;
	for (int i=0; i<n; i++) {
		pair<int, int> q = query(0, 0, n-1, ranges[loc[i]].l, i-1);
		if (q.first >= i) {
			swp_a = q.second;
			swp_b = i;
			break;
		}
		update(0, 0, n-1, i, ranges[loc[i]].r);
	}
	if (swp_a == -1) {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) {
			cout << val[i]+1 << " ";
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
		for (int i=0; i<n; i++) {
			cout << val[i]+1 << " ";
		}
		cout << endl;
		for (int i=0; i<n; i++) {
			if (val[i] == swp_a) {
				cout << swp_b+1 << " ";
			} else if (val[i] == swp_b) {
				cout << swp_a+1 << " ";
			} else {
				cout << val[i]+1 << " ";
			}
		}
		cout << endl;
	}
}