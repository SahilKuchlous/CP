#include <iostream>
#include <set>
using namespace std;
int n, m;
set< pair<int, int> > dp[100100];
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		dp[i].insert(make_pair(-1, 0));
	}
	int s, e, w;
	for (int i=0; i<m; i++) {
		cin >> s >> e >> w;
		s--; e--;
		int len = prev(dp[s].lower_bound(make_pair(w, -1)))->second+1;
		int best = prev(dp[e].lower_bound(make_pair(w, -1)))->second;
		if (best >= len) continue;
		while (dp[e].lower_bound(make_pair(w, len)) != dp[e].end()) {
			if (dp[e].lower_bound(make_pair(w, len))->second > len) break;
			dp[e].erase(dp[e].lower_bound(make_pair(w, len)));
		}
		dp[e].insert(make_pair(w, len));
		o = max(o, len);
	}
	cout << o << endl;
}