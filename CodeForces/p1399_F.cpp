#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 3005
int n;
pair<int, int> ranges[MAXN];
vector<int> pts;
int pos[200005];
int dp[2*MAXN][2*MAXN];
bool vis[2*MAXN][2*MAXN];
vector<int> e_pts[2*MAXN];
void reset () {
	pts.clear();
	for (int i=0; i<2*n; i++) {
		e_pts[i].clear();
		for (int j=0; j<2*n; j++) {
			vis[i][j] = false;
		}
	}
}
int solve (int l, int r) {
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = true;
	dp[l][r] = 0;
	for (auto i: e_pts[l]) {
		if (i == r) dp[l][r]++;
	}
	if (l == r) return dp[l][r];
	int best = max(solve(l+1, r), solve(l, r-1));
	for (auto i: e_pts[l]) {
		if (i >= r) continue;
		best = max(best, solve(l, i)+solve(i+1, r));
	}
	dp[l][r] += best;
	return dp[l][r];
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		reset();
		for (int i=0; i<n; i++) {
			cin >> ranges[i].first >> ranges[i].second;
			pts.push_back(ranges[i].first);
			pts.push_back(ranges[i].second);
		}
		sort(pts.begin(), pts.end());
		pts.erase(unique(pts.begin(), pts.end()), pts.end());
		for (int i=0; i<pts.size(); i++) {
			pos[pts[i]] = i;
		}
		for (int i=0; i<n; i++) {
			ranges[i].first = pos[ranges[i].first];
			ranges[i].second = pos[ranges[i].second];
			e_pts[ranges[i].first].push_back(ranges[i].second);
		}
		cout << solve(0, pts.size()-1) << endl;
	}
}