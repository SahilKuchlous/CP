#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int presum[1000100];
int sufsum[1000100];
pair<int, int> segtree[4000100];
pair<int, int> merge (pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return a;
	if (b.first < a.first) return b;
	return make_pair(a.first, max(a.second, b.second));
}
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x] = make_pair(sufsum[l], l);
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x] = merge(segtree[2*x+1], segtree[2*x+2]);
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return make_pair(1e8, -1);
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	pair<int, int> p1 = query(2*x+1, l, m, a, b);
	pair<int, int> p2 = query(2*x+2, m+1, r, a, b);
	return merge(p1, p2);
}
int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0; i<n; i++) {
		presum[i+1] = presum[i] + (s.at(i) == 'p' ? 1 : -1); 
	}
	for (int i=n-1; i>=0; i--) {
		sufsum[i+1] = sufsum[i+2] + (s.at(i) == 'p' ? 1 : -1);
	}
	sufsum[0] = 1e8;
	vector<int> prepos[2*n+10];
	for (int i=0; i<=n; i++) {
		prepos[n+presum[i]].push_back(i);
	}
	create(0, 0, n+1);
	int o = 0;
	for (int i=1; i<=n; i++) {
		vector<int>::iterator pos = lower_bound(prepos[n+presum[i-1]-1].begin(), prepos[n+presum[i-1]-1].end(), i);
		int last = n+1;
		if (pos != prepos[n+presum[i-1]-1].end()) last = (*pos);
		if (last <= i) continue;
		last = query(0, 0, n+1, i, last).second;
		o = max(o, last-i);
	}
	cout << o << endl;
}