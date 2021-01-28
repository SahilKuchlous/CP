#include <iostream>
using namespace std;
void solve () {
	int n, q;
	cin >> n >> q;
	string cmd;
	cin >> cmd;
	int ttl[n+1];
	ttl[0] = 0;
	for (int i=1; i<=n; i++) {
		ttl[i] = ttl[i-1]+(cmd[i-1]=='+'?1:-1);
	}
	pair<int, int> f[n+1];
	f[0] = make_pair(0, 0);
	for (int i=1; i<=n; i++) {
		f[i] = make_pair(max(f[i-1].first, ttl[i]), min(f[i-1].second, ttl[i]));
	}
	pair<int, int> b[n+1];
	b[n] = make_pair(0, 0);
	for (int i=n-1; i>=0; i--) {
		b[i] = make_pair(max(b[i+1].first+(cmd[i]=='+'?1:-1), 0), min(b[i+1].second+(cmd[i]=='+'?1:-1), 0));
	}
	int l, r;
	for (int i=0; i<q; i++) {
		cin >> l >> r;
		l--; r--;
		int mx = max(f[l].first, ttl[l]+b[r+1].first);
		int mn = min(f[l].second, ttl[l]+b[r+1].second);
		cout << mx-mn+1 << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}