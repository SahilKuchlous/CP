#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 1000005
int n, q;
int a[MAXN];
pair< pair<int, int>, int > qry[MAXN];
long long o[MAXN];
pair<long long, int> segtree[4*MAXN];
void init (int x, int l, int r) {
	if (l == r) {
		segtree[x].first = -l;
		segtree[x].second = 1;
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
	segtree[x].first = segtree[2*x+1].first+segtree[2*x+2].first;
	segtree[x].second = segtree[2*x+1].second+segtree[2*x+2].second;
}
void update (int x, int l, int r, int p, int v) {
	if (r < p || p < l) return;
	if (l == r) {
		segtree[x].first = v;
		segtree[x].second = 0;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x].first = segtree[2*x+1].first+segtree[2*x+2].first;
	segtree[x].second = segtree[2*x+1].second+segtree[2*x+2].second;
}
pair<long long, int> query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return make_pair(0, 0);
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	pair<long long, int> ans = query(2*x+1, l, m, a, b);
	pair<long long, int> temp = query(2*x+2, m+1, r, a, b);
	ans.first += temp.first; ans.second += temp.second;
	return ans;
}
void solve () {
	init(0, 0, n-1);
	int ptr = 0;
	stack< pair<int, int> > lose;
	for (int i=0; i<n; i++) {
		while (lose.size() > 0 && lose.top().second < a[i]) {
			update(0, 0, n-1, lose.top().first, i-lose.top().first-1);
			lose.pop();
		}
		lose.push(make_pair(i, a[i]));
		while (qry[ptr].first.second == i) {
			pair<long long, int> ans = query(0, 0, n-1, qry[ptr].first.first, qry[ptr].first.second);
			o[qry[ptr].second] += ans.first+1ll*i*ans.second;
			ptr++;
		}
	}
}
bool func (const pair< pair<int, int>, int > &p1, const pair< pair<int, int>, int > &p2) {
	return p1.first.second < p2.first.second;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<q; i++) {
		cin >> qry[i].first.first;
		qry[i].first.first--;
	}
	for (int i=0; i<q; i++) {
		cin >> qry[i].first.second;
		qry[i].first.second--;
	}
	for (int i=0; i<q; i++) {
		qry[i].second = i;
		o[i] = qry[i].first.second-qry[i].first.first+1;
	}
	sort(qry, qry+q, func);
	solve();
	reverse(a, a+n);
	for (int i=0; i<q; i++) {
		swap(qry[i].first.first, qry[i].first.second);
		qry[i].first.first = n-qry[i].first.first-1;
		qry[i].first.second = n-qry[i].first.second-1;
	}
	sort(qry, qry+q, func);
	solve();
	for (int i=0; i<q; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}