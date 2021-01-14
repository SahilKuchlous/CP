#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, k;
vector< pair<int, int> > adj[500100];
long long dp_inc[500100];
long long dp_exc[500100];
void dfs (int x, int p) {
	dp_inc[x] = dp_exc[x] = 0;
	multiset< int, greater<int> > opts;
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs(i.first, x);
			dp_inc[x] += dp_exc[i.first];
			dp_exc[x] += dp_exc[i.first];
			if (dp_inc[i.first]+i.second > dp_exc[i.first]) {
				opts.insert(dp_inc[i.first]+i.second-dp_exc[i.first]);
			}
		}
	}
	int cnt = 0;
	while (opts.size() > 0) {
		if (cnt == k-1) {
			dp_exc[x] += *opts.begin();
			break;
		}
		dp_inc[x] += *opts.begin();
		dp_exc[x] += *opts.begin();
		opts.erase(opts.begin());
		cnt++;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=0; i<n; i++) {
			adj[i].clear();
		}
		int ai, bi, ci;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi >> ci;
			ai--;
			bi--;
			adj[ai].push_back(make_pair(bi, ci));
			adj[bi].push_back(make_pair(ai, ci));
		}
		dfs(0, 0);
		cout << dp_exc[0] << endl;
	}
}