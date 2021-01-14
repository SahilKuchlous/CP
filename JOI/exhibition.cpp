#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100005
int n, m;
pair<int, int> pics[MAXN];
vector<int> frames;
int dp[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> pics[i].second >> pics[i].first;
	}
	for (int i=0; i<m; i++) {
		frames.push_back(0);
		cin >> frames[i];
	}
	sort(frames.begin(), frames.end());
	for (int i=0; i<n; i++) {
		pics[i].second = lower_bound(frames.begin(), frames.end(), pics[i].second)-frames.begin();
	}
	sort(pics, pics+n);
	dp[n] = 0;
	int best = 0;
	for (int i=n-1; i>=0; i--) {
		dp[i] = min(best+1, m-pics[i].second);
		best = max(best, dp[i]);
	}
	cout << best << endl;
}