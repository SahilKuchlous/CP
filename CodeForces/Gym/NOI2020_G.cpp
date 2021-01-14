#include <iostream>
#include <set>
#include <map>
using namespace std;
int n, m, v;
int sci[6000];
set< pair<int, int> > adj[6000];
long long memo[6000][6001];
long long rec (int x, int r) {
	if (r < 0) {
		return 0;
	}
	if (memo[x][r] > -1) {
		return memo[x][r];
	}
	long long o = 0;
	for (auto i: adj[x]) {
		o = max(o, rec(i.first, r-i.second));
	}
	memo[x][r] = o+sci[x];
	return o+sci[x];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> v;
		for (int i=0; i<n; i++) {
			cin >> sci[i];
			adj[i].clear();
		}
		int ai, bi, ci;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi >> ci;
			adj[ai].insert(make_pair(bi, ci));
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<=v; j++) {
				memo[i][j] = -1;
			}
		}
		cout << rec(0, v) << endl;
	}
}