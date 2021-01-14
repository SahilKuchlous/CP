#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 500005
struct build {
	int id;
	int ht, cost;
	bool operator < (const build b) const {
		return ht > b.ht;
	}
};
int n;
build builds[MAXN];
int sh, eh;
long long dp[MAXN];
stack< pair<long long, int> > costs;
long long o = 1e16;
void init () {
	while (costs.size() > 0) costs.pop();
	o = 1e16;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		for (int i=0; i<n; i++) {
			cin >> builds[i].ht >> builds[i].cost;
			builds[i].id = i;
		}
		sh = builds[0].ht;
		eh = builds[n-1].ht;
		sort(builds, builds+n);
		for (int i=0; i<n; i++) {
			dp[i] = 1e16;
		}
		costs.push(make_pair(-1, -1));
		for (int i=0; i<n; i++) {
			dp[builds[i].id] = 1ll*builds[i].cost*max(0, eh-builds[i].ht);
			while (costs.top().first >= builds[i].cost) {
				costs.pop();
			}
			int nxt = costs.top().second;
			if (nxt > -1) dp[builds[i].id] = min(dp[builds[i].id], dp[builds[nxt].id]+1ll*builds[i].cost*(builds[nxt].ht-builds[i].ht));
			costs.push(make_pair(builds[i].cost, i));
			if (builds[i].ht <= sh) o = min(o, dp[builds[i].id]);
		}
		cout << o << '\n';
	}
}