#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 200005
int n, m;
long long k;
vector< pair<long long, pair<int, int> > > edges;
int par[MAXN];
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void init () {
	edges.clear();
	for (int i=0; i<n; i++) {
		par[i] = i;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		init();
		int ai, bi;
		long long ci;
		long long closest = 1e13;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi >> ci;
			ai--; bi--;
			edges.push_back(make_pair(ci, make_pair(ai, bi)));
			if (abs(closest-k) >= abs(ci-k)) closest = ci;
		}
		sort(edges.begin(), edges.end());
		long long ttl = 0;
		for (auto i: edges) {
			int r1 = root(i.second.first), r2 = root(i.second.second);
			if (r1 == r2) continue;
			par[r2] = r1;
			if (i.first > k) ttl += i.first-k;
		}
		if (ttl == 0) {
			cout << abs(closest-k) << '\n';
		} else {
			cout << ttl << '\n';
		}
	}
}