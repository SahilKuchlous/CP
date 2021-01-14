#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
vector<int> adj[3000];
int val[3000];
vector< pair<int, int> > dp[3000];
int sz[3000];
int pos[3000];
pair<int, int> sum (pair<int, int> &p1, pair<int, int> &p2) {
	return make_pair(p1.first+p2.first, p1.second+p2.second);
}
pair<int, int> sub (pair<int, int> &p1, pair<int, int> &p2) {
	return make_pair(p1.first-p2.first, p1.second-p2.second);
}
void dfs (int x, int p) {
	sz[x] = 1;
	set< pair< pair<int, int>, int > > dif;
	pair<int, int> cur = make_pair(0, val[x]);
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x);
			sz[x] += sz[i];
			cur = sum(cur, dp[i][0]);
			dif.insert(make_pair(sub(dp[i][1], dp[i][0]), i));
			pos[i] = 0;
		}
	}
	dp[x] = vector< pair<int, int> > (min(m, sz[x])+1, make_pair(-1, -1));
	dp[x][0] = cur;
	for (int i=1; i<min(m, sz[x]); i++) {
		pair<int, int> best_val = prev(dif.end())->first;
		int best_i = prev(dif.end())->second;
		dif.erase(prev(dif.end()));
		if (pos[best_i] < min(m, sz[x])) {
			dif.insert(make_pair(sub(dp[best_i][pos[best_i]+1], dp[best_i][pos[best_i]]), best_i));
		}
		cur = sum(cur, best_val);
		dp[x][i] = cur;
	}
	vector< pair<int, int> > new_dp (min(m, sz[x])+1, make_pair(-1, -1));
	new_dp[0] = dp[x][0];
	cout << x << " " << 0 << " " << new_dp[0].first << " " << new_dp[0].second << endl;
	for (int i=1; i<=min(m, sz[x]); i++) {
		if (dp[x][i-1].second > 0) {
			new_dp[i] = make_pair(dp[x][i-1].first+1, 0);
		} else {
			new_dp[i] = make_pair(dp[x][i-1].first, 0);
		}
		new_dp[i] = max(new_dp[i], dp[x][i]);
		cout << x << " " << i << " " << new_dp[i].first << " " << new_dp[i].second << endl;
	}
	dp[x] = new_dp;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			val[i] = 0;
			adj[i].clear();
			dp[i].clear();
		}
		int ai, bi;
		for (int i=0; i<n; i++) {
			cin >> ai;
			val[i] -= ai;
		}
		for (int i=0; i<n; i++) {
			cin >> ai;
			val[i] += ai;
		}
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		dfs(0, 0);
		cout << dp[0][m].first << endl;
	}
}