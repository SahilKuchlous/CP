#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
int m, n;
int a[MAXN], b[MAXN];
vector< pair<int, pair<int, int> > > edges;
int par[2*MAXN];
int root (int a) {
	if (a == par[a]) return a;
	par[a] = par[par[a]];
	return root(par[a]);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i=0; i<m; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	int cnt, inp;
	for (int i=0; i<m; i++) {
		cin >> cnt;
		for (int j=0; j<cnt; j++) {
			cin >> inp;
			inp--;
			edges.push_back(make_pair(-(a[i]+b[inp]), make_pair(i, MAXN+inp)));
		}
	}
	for (int i=0; i<2*MAXN; i++) {
		par[i] = i;
	}
	sort(edges.begin(), edges.end());
	long long cost = 0;
	for (auto i: edges) {
		int r1 = root(i.second.first), r2 = root(i.second.second);
		if (r1 == r2) {
			cost += -i.first;
			continue;
		}
		par[r2] = r1;
	}
	cout << cost << endl;
}