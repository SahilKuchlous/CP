#include <iostream>
#include <set>
using namespace std;
struct edge {
	int a, b, wt;
};
int n, w;
set< pair<int, int> > adj[210];
edge edges[210];
int cnt = 0;
int dfs (int x, int p, int g) {
	if (x == g) return n;
	for (auto i: adj[x]) {
		if (i.first != p) {
			int val = dfs(i.first, x, g);
			if (val > -1) {
				if (val == n) {
					return i.second;
				} else {
					return (edges[i.second].wt>edges[val].wt ? i.second:val);
				}
			}
		}
	}
	return -1;
}
int main () {
	cin >> n >> w;
	int ai, bi, ci;
	long long o = 0;
	for (int i=0; i<w; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		int val = dfs(ai, ai, bi);
		if (val == -1 || edges[val].wt > ci) {
			if (val > -1) {
				o -= edges[val].wt;
				adj[edges[val].a].erase(make_pair(edges[val].b, val));
				adj[edges[val].b].erase(make_pair(edges[val].a, val));
			} else {
				val = cnt;
				cnt++;
			}
			edges[val] = {ai, bi, ci};
			o += edges[val].wt;
			adj[edges[val].a].insert(make_pair(edges[val].b, val));
			adj[edges[val].b].insert(make_pair(edges[val].a, val));
		}
		if (cnt < n-1) {
			cout << -1 << endl;
		} else {
			cout << o << endl;
		}
	}
}