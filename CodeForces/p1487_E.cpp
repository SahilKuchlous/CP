#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 150005
int n[4];
int a[4][MAXN];
vector< pair<long long, int> > adj[4][MAXN];
vector< pair<long long, int> > ord;
long long dp[4][MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0; i<4; i++) {
		cin >> n[i];
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<n[i]; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=0; i<n[0]; i++) {
		dp[0][i] = a[0][i];
	}
	for (int i=1; i<4; i++) {
		ord.clear();
		for (int j=0; j<n[i-1]; j++) {
			ord.push_back(make_pair(dp[i-1][j], j));
		}
		sort(ord.begin(), ord.end());
		int cnt;
		cin >> cnt;
		int ai, bi;
		for (int j=0; j<cnt; j++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[i][bi].push_back(make_pair(dp[i-1][ai], ai));
		}
		for (int j=0; j<n[i]; j++) {
			sort(adj[i][j].begin(), adj[i][j].end());
			dp[i][j] = 1e12;
			for (int k=0; k<ord.size(); k++) {
				if (adj[i][j].size() > k && adj[i][j][k].second == ord[k].second) continue;
				dp[i][j] = dp[i-1][ord[k].second]+a[i][j];
				break;
			}
		}
	}
	long long o = 1e12;
	for (int i=0; i<n[3]; i++) {
		o = min(o, dp[3][i]);
	}
	if (o >= 1e12) {
		cout << -1 << endl;
	} else {
		cout << o << endl;
	}
}