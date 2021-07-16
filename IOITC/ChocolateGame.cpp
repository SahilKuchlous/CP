#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MAXC 10000005
int n, q;
int p[MAXN];
int ans[MAXC];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	long long prod = 1;
	for (int i=0; i<n; i++) {
		cin >> p[i];
		if (prod <= 1e10) prod *= p[i];
	}
	sort(p, p+n);
	ans[0] = 0;
	for (int i=1; i<MAXC; i++) {
		ans[i] = 1e9;
		int max_mod = 0;
		for (int j=n-1; j>=0; j--) {
			if (max_mod >= p[j]) break;
			max_mod = max(max_mod, i%p[j]);
		}
		ans[i] = ans[i-max_mod]+1;
	}
	while (q--) {
		int cnt;
		cin >> cnt;
		if (cnt >= prod || ans[cnt] >= 1e9) {
			cout << "oo" << '\n';
			continue;
		}
		cout << ans[cnt] << '\n';
	}
}