#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string seq;
int n;
int segtree[400100];
int lazy[400100];
void push (int x, int l, int r) {
	if (lazy[x] == 0) return;
	segtree[x] += lazy[x];
	if (l != r) {
		lazy[2*x+1] += lazy[x];
		lazy[2*x+2] += lazy[x];
	}
	lazy[x] = 0;
}
void update (int x, int l, int r, int a, int b, int v) {
	push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] += v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
int query (int x, int l, int r, int a, int b) {
	push(x, l, r);
	if (r < a || b < l) return 1e8;
	if (a <= l && r <= b) return segtree[x];
	int o = 1e8;
	int m = (l+r)/2;
	o = min(o, query(2*x+1, l, m, a, b));
	o = min(o, query(2*x+2, m+1, r, a, b));
	return o;
}
long long total = 0;
vector< pair<int, int> > v;
int main () {
	cin >> seq;
	n = seq.length();
	char o[n];
	int ai, bi;
	for (int i=0; i<n; i++) {
		if (seq.at(i) == '(') {
			o[i] = '(';
			update(0, 0, n-1, i, n-1, 1);
		} else if (seq.at(i) == ')') {
			o[i] = ')';
			update(0, 0, n-1, i, n-1, -1);
		} else {
			update(0, 0, n-1, i, n-1, 1);
			cin >> ai >> bi;
			total += ai;
			v.push_back(make_pair(bi-ai, i));
		}
	}
	sort(v.begin(), v.end());
	for (int i=0; i<v.size(); i++) {
		if (query(0, 0, n-1, v[i].second, n-1) <= 1) {
			o[v[i].second] = '(';
			continue;
		}
		o[v[i].second] = ')';
		total += v[i].first;
		update(0, 0, n-1, v[i].second, n-1, -2);
	}
	bool pos = true;
	int cur = 0;
	for (int i=0; i<n; i++) {
		cur += (o[i] == '(' ? 1:-1);
		if (cur < 0) pos = false;
	}
	if (cur != 0) pos = false;
	if (pos) {
		cout << total << endl;
		for (int i=0; i<n; i++) {
			cout << o[i];
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}