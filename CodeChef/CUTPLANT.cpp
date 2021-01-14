#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
int n;
int a[100100];
int b[100100];
pair<int, int> segtree[400100];
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x] = make_pair(a[l], b[l]);
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x].first = min(segtree[2*x+1].first, segtree[2*x+2].first);
	segtree[x].second = max(segtree[2*x+1].second, segtree[2*x+2].second);
}
void update (int x, int l, int r, int v) {
	if (v < l || v > r) {
		return;
	}
	if (l == r) {
		segtree[x].first = segtree[x].second;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, v);
	update(2*x+2, m+1, r, v);
	segtree[x].first = min(segtree[2*x+1].first, segtree[2*x+2].first);
}
bool query (int x, int l, int r, int a, int b, int v) {
	if (r < a || b < l) {
		return false;
	}
	if (a <= l && r <= b) {
		if (segtree[x].first < v || segtree[x].second > v) {
			return true;
		}
		return false;
	}
	int m = (l+r)/2;
	if (query(2*x+1, l, m, a, b, v)) {
		return true;
	}
	if (query(2*x+2, m+1, r, a, b, v)) {
		return true;
	}
	return false;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		set< int, greater<int> > heights;
		map< int, vector<int> > ind;
		bool pos = true;
		for (int i=0; i<n; i++) {
			cin >> b[i];
			heights.insert(b[i]);
			if (b[i] < a[i]) ind[b[i]].push_back(i);
			if (b[i] > a[i]) {
				pos = false;
			}
		}
		if (!pos) {
			cout << -1 << endl;
			return 0;
		}
		create(0, 0, n-1);
		long long o = 0;
		for (auto i: heights) {
			if (ind[i].size()>0) o++;
			for (int j=1; j<ind[i].size(); j++) {
				if (query(0, 0, n-1, ind[i][j-1], ind[i][j], i)) {
					o++;
				}
			}
			for (int j=0; j<ind[i].size(); j++) {
				update(0, 0, n-1, ind[i][j]);
			}
		}
		cout << o << endl;
	}
}