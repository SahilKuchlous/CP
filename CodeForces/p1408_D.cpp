#include <iostream>
using namespace std;
#define MAXN 2005
#define MAXI 1000005
int n, m;
pair<int, int> pos_r[MAXN];
pair<int, int> pos_s[MAXN];
int cost[MAXI];
int o = MAXI;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> pos_r[i].first >> pos_r[i].second;
	}
	for (int i=0; i<m; i++) {
		cin >> pos_s[i].first >> pos_s[i].second;
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (pos_r[j].first <= pos_s[i].first) cost[pos_s[i].first-pos_r[j].first] = max(cost[pos_s[i].first-pos_r[j].first], pos_s[i].second-pos_r[j].second+1);
		}
	}
	int mx = 0;
	for (int i=MAXI-1; i>=0; i--) {
		mx = max(mx, cost[i]);
		o = min(o, mx+i);
	}
	cout << o << endl;
}