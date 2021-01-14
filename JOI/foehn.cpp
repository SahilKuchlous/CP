#include <iostream>
using namespace std;
#define MAXN 200005
#define int long long
int n, q, s, t;
int org[MAXN];
long long dif[MAXN];
long long o = 0;
void upd (int v, bool add) {
	if (v > 0) {
		o += 1ll*v*s*(add?-1:1);
	} else {
		o += 1ll*v*t*(add?-1:1);
	}
}
signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q >> s >> t;
	for (int i=0; i<n+1; i++) {
		cin >> org[i];
	}
	for (int i=0; i<n; i++) {
		dif[i] = org[i+1]-org[i];
		upd(dif[i], 1);
	}
	int l, r, v;
	while (q--) {
		cin >> l >> r >> v;
		l--;
		upd(dif[l], 0);
		dif[l] += v;
		upd(dif[l], 1);
		if (r < n) {
			upd(dif[r], 0);
			dif[r] -= v;
			upd(dif[r], 1);
		}
		cout << o << '\n';
	}
}