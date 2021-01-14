#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
const int N = 2e5 + 7, mod = 1e9 + 7, K = 3007;
int f[N], inv[N], d[K];
pair<int, int> a[K];
int binpow (int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) (res *= a) %= mod, --b;
		else (a *= a) %= mod, b >>= 1;
	}
	return res;
}
int inverse (int x) {
	return binpow(x, mod - 2);
}
void preset() {
	f[0] = 1, inv[0] = 1;
	for (int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % mod, inv[i] = inverse(f[i]);
}
int C (int k, int n) {
	if (k > n) return 0;
	return ((f[n] * inv[k]) % mod) * inv[n - k] % mod;
}
signed main() {
	preset();
	int h, w, n;
	cin >> h >> w >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	a[n] = make_pair(h, w);
	sort(a, a+n);
	for(int i=0; i<=n; i++) {
		d[i] = C(a[i].first - 1, a[i].first + a[i].second - 2);
		for(int j=i-1; j>=0; j--) {
			int to = C(a[i].first - a[j].first, a[i].first + a[i].second - a[j].first - a[j].second);
			d[i] = (d[i] - d[j] * to) % mod;
			d[i] = (d[i] + mod) % mod;
		}
	}
	cout << d[n] << endl;
}
