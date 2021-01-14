#include <iostream>
#include <vector>
using namespace std;
int n, m;
pair<int, int> ranges[200100];
int score[200100];
vector<int> s[200100], e[200100];
long long dp[200100];
long long o = 0;
long long cur = 0;
long long segtree[800100];
long long lazy[800100];
void push (int x, int l, int r) {
	if (lazy[x] == 0) return;
	segtree[x] += lazy[x];
	if (l != r) {
		lazy[2*x+1] += lazy[x];
		lazy[2*x+2] += lazy[x];
	}
	lazy[x] = 0;
}
void update1 (int x, int l, int r, int p, long long v) {
	push(x, l, r);
	if (p < l || p > r) return;
	segtree[x] = max(segtree[x], v);
	if (l == r) return;
	int m = (l+r)/2;
	update1(2*x+1, l, m, p, v);
	update1(2*x+2, m+1, r, p, v);
}
void update2 (int x, int l, int r, int a, int b, long long v) {
	push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] += v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update2(2*x+1, l, m, a, b, v);
	update2(2*x+2, m+1, r, a, b, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> ranges[i].first >> ranges[i].second >> score[i];
		ranges[i].first--; ranges[i].second--;
		s[ranges[i].first].push_back(i);
		e[ranges[i].second].push_back(i);
	}
	for (int i=0; i<n; i++) {
		for (auto j: s[i]) {
			cur += score[j];
		}
		push(0, 0, n-1);
		dp[i] = cur+segtree[0];
		o = max(o, dp[i]);
		update1(0, 0, n-1, i, segtree[0]);
		for (auto j: e[i]) {
			cur -= score[j];
			update2(0, 0, n-1, ranges[j].first, ranges[j].second, score[j]);
		}
	}
	cout << o << endl;
}