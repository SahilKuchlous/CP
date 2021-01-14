#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair< int, pair<int, int> > items[n+1];
	map< pair< int, pair<int, int> >, int > ind;
	items[0] = make_pair(0, make_pair(0, 0));
	for (int i=1; i<=n; i++) {
		cin >> items[i].second.first >> items[i].first >> items[i].second.second;
		ind[items[i]] = i;
	}
	sort(items, items+n+1);
	int dp[110][2100];
	int seq[110][2100];
	for (int i=0; i<110; i++) {
		for (int j=0; j<2200; j++) {
			dp[i][j] = 0;
		}
	}
	int best_val, best_i;
	for (int i=1; i<=n; i++) {
		for (int j=items[i].second.first; j<items[i].first; j++) {
			best_val = -1;
			best_i = -1;
			for (int k=0; k<i; k++) {
				if (dp[k][j-items[i].second.first] < best_val) {
					best_val = dp[k][j-items[i].second.first]+items[i].second.second;
					best_i = k;
				}
			}
			if (best_val > dp[i][j-1]) {
				dp[i][j] = best_val;
				seq[i][j] = best_i;
			} else {
				dp[i][j] = dp[i][j-1];
				seq[i][j] = seq[i][j-1];
			}
		}
	}
	int o = 0;
	for (int i=1; i<=n; i++) {
		cout << ind[items[i]] << " " << dp[i][items[i].first-1] << endl;
		o = max(o, dp[i][items[i].first-1]);
	}
	cout << o << endl;
}