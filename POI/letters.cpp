#include <iostream>
#include <vector>
using namespace std;
int segtree[4000000];
void update (int x, int l, int r, int p) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[x]++;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p);
	update(2*x+2, m+1, r, p);
	segtree[x] = segtree[2*x+1]+segtree[2*x+2];
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return query(2*x+1, l, m, a, b)+query(2*x+2, m+1, r, a, b);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<int> opts[26];
	for (int i=0; i<a.length(); i++) {
		opts[a[i]-'A'].push_back(i);
	}
	int cnt[26];
	for (int i=0; i<26; i++) {
		cnt[i] = 0;
	}
	long long o = 0;
	for (auto i: b) {
		o += opts[i-'A'][cnt[i-'A']]-query(0, 0, n-1, 0, opts[i-'A'][cnt[i-'A']]);
		update(0, 0, n-1, opts[i-'A'][cnt[i-'A']]);
		cnt[i-'A']++;
	}
	cout << o << endl;
}