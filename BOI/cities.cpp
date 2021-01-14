#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, m;
int imp[5];
vector< pair<int, int> > adj[100100];
long long dp[1<<5][100100];
bool vis[100100];
long long o = 1e16;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
	for (int i=0; i<k; i++) {
		cin >> imp[i];
		imp[i]--;
	}
	int ai, bi, wi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> wi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, wi));
		adj[bi].push_back(make_pair(ai, wi));
	}
	for (int i=0; i<(1<<k); i++) {
		for (int j=0; j<n; j++) {
			dp[i][j] = 1e16;
		}
	}
	for (int i=0; i<k; i++) {
		dp[1<<i][imp[i]] = 0;
	}
	for (int i=1; i<(1<<k); i++) {
		for (int sub=i; sub>0; sub=(sub-1)&i) {
			if ((sub ^ i) > sub) continue;
			for (int j=0; j<n; j++) {
				dp[i][j] = min(dp[i][j], dp[sub][j]+dp[i^sub][j]);
			}
		}
		priority_queue< pair<long long, int> > ord;
		for (int j=0; j<n; j++) {
			vis[j] = false;
			if (dp[i][j] < 1e16) ord.push(make_pair(-dp[i][j], j));
		}
		while (ord.size() > 0) {
			pair<long long, int> cur = ord.top();
			ord.pop();
			cur.first = -cur.first;
			if (vis[cur.second]) continue;
			vis[cur.second] = true;
			for (auto j: adj[cur.second]) {
				if (cur.first+j.second < dp[i][j.first]) {
					dp[i][j.first] = cur.first+j.second;
					ord.push(make_pair(-dp[i][j.first], j.first));
				}
			}
		}
	}
	for (int j=0; j<n; j++) {
		o = min(o, dp[(1<<k)-1][j]);
	}
	cout << o << endl;
}