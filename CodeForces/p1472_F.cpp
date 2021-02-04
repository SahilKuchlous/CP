#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve () {
	int n, m;
	cin >> n >> m;
	pair<int, int> inp[m];
	for (int i=0; i<m; i++) {
		cin >> inp[i].second >> inp[i].first;
	}
	sort(inp, inp+m);
	vector< pair<int, int> > obs;
	for (int i=0; i<m; i++) {
		if (i > 0 && inp[i].first == inp[i-1].first) {
			obs.back().second = 0;
			continue;
		}
		obs.push_back(inp[i]);
	}
	int skew = 0;
	int pos = 0;
	bool o = true;
	for (int i=0; i<obs.size(); i++) {
		if (skew == 0) {
			skew = obs[i].second;
			pos = obs[i].first;
			continue;
		}
		if (obs[i].second == 0) {
			o = false;
			continue;
		}
		if ((skew != obs[i].second) ^ ((obs[i].first-pos)%2)) {
			skew = 0;
			continue;
		}
		o = false;
	}
	if (skew != 0) o = false;
	if (o) {
		cout << "YES" << endl;
	} else { 
		cout << "NO" << endl;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}