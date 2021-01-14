#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int, int> masts[100100];
int left_i, right_i;
pair<int, int> segtree[400100];
int lazy[400100];
void push (int x, int l, int r) {
	segtree[x].first += lazy[x];
	segtree[x].second += lazy[x];
	if (l != r) {
		lazy[2*x+1] += lazy[x];
		lazy[2*x+2] += lazy[x];
	}
	lazy[x] = 0;
}
int query1 (int x, int l, int r, int p) {
	if (lazy[x] != 0) push(x, l, r);
	if (l == r) {
		return segtree[x].first;
	}
	int m = (l+r)/2;
	if (m >= p) return query1(2*x+1, l, m, p);
	return query1(2*x+2, m+1, r, p);
}
int query2 (int x, int l, int r, int v) {
	if (lazy[x] != 0) push(x, l, r);
	if (l == r) {
		return (segtree[x].first<v ? l:-1);
	}
	int m = (l+r)/2;
	if (lazy[2*x+2] != 0) push(2*x+2, m+1, r);
	if (segtree[2*x+2].first < v) return query2(2*x+2, m+1, r, v);
	return query2(2*x+1, l, m, v);
}
int query3 (int x, int l, int r, int v) {
	if (lazy[x] != 0) push(x, l, r);
	if (l == r) {
		return (segtree[x].first>v ? l:right_i+1);
	}
	int m = (l+r)/2;
	if (lazy[2*x+1] != 0) push(2*x+1, l, m);
	if (segtree[2*x+1].second > v) return query3(2*x+1, l, m, v);
	return query3(2*x+2, m+1, r, v);
}
void update (int x, int l, int r, int a, int b) {
	if (lazy[x] != 0) push(x, l, r);
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[x]++;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b);
	update(2*x+2, m+1, r, a, b);
	segtree[x].first = min(segtree[2*x+1].first, segtree[2*x+2].first);
	segtree[x].second = max(segtree[2*x+1].second, segtree[2*x+2].second);
} 
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> masts[i].first >> masts[i].second;
	}
	sort(masts, masts+n);
	right_i = masts[n-1].first-1;
	for (int i=0; i<n; i++) {
		left_i = right_i-masts[i].first+1;
		int mid = query1(0, 0, right_i, left_i+masts[i].second-1);
		int p1 = query2(0, 0, right_i, mid);
		int p2 = query3(0, 0, right_i, mid)-1;
		int rem = masts[i].second;
		if (p1 >= left_i) {
			update(0, 0, right_i, left_i, p1);
			rem -= p1-left_i+1;
		}
		update(0, 0, right_i, p2-rem+1, p2);
	}
	long long o = 0;
	int prev = -1;
	for (int i=0; i<=right_i; i++) {
		int val = query1(0, 0, right_i, i);
		o += 1ll*val*(val-1)/2;
		prev = val;
	}
	cout << o << endl;
}