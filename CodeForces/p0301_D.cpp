#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int seq[200100];
int pos[200100];
long long ans[200100];
long long segtree[800100];
void add (int x, int l, int r, int a) {
	if (a < l || a > r) {
		return;
	}
	segtree[x]++;
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	add(2*x+1, l, m, a);
	add(2*x+2, m+1, r, a);
}
long long query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return 0;
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	long long ans = 0;
	ans += query(2*x+1, l, m, a, b);
	ans += query(2*x+2, m+1, r, a, b);
	return ans;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> seq[i];
		pos[seq[i]] = i;
	}
	vector< pair< pair<int, int>, int> > q(m);
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--;
		bi--;
		q[i] = make_pair(make_pair(bi, ai), i);
	}
	sort(q.begin(), q.end());
	for (int i=0; i<4*n; i++) {
		segtree[i] = 0;
	}
	int qi = 0;
	for (int i=0; i<n; i++) {
		for (int j=1; j*j<=seq[i]; j++) {
			if (seq[i]%j == 0) {
				if (pos[j] < i) add(0, 0, n-1, pos[j]);
				if (j*j<seq[i] && pos[seq[i]/j] < i) add(0, 0, n-1, pos[seq[i]/j]);
			}
		}
		for (int j=seq[i]; j<=n; j+=seq[i]) {
			if (pos[j] <= i) add(0, 0, n-1, pos[j]);
		}
		while (qi < m && q[qi].first.first == i) {
			ans[q[qi].second] = query(0, 0, n-1, 0, q[qi].first.first)-query(0, 0, n-1, 0, q[qi].first.second-1);
			qi++;
		}
	}
	for (int i=0; i<m; i++) {
		cout << ans[i] << '\n';
	}
}