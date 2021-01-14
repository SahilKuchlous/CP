#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> sets[n];
		vector<int> values;
		int cnt, inp;
		for (int i=0; i<n; i++) {
			cin >> cnt;
			for (int j=0; j<cnt; j++) {
				cin >> inp;
				sets[i].push_back(inp);
				values.push_back(inp);
			}
		}
		sort(values.begin(), values.end());
		values.resize(unique(values.begin(), values.end())-values.begin());
		for (int i=0; i<n; i++) {
			for (int j=0; j<sets[i].size(); j++) {
				sets[i][j] = lower_bound(values.begin(), values.end(), sets[i][j])-values.begin();
			}
			sort(sets[i].begin(), sets[i].end());
		}
		int sq = 316;
		bool pres[values.size()];
		for (int i=0; i<values.size(); i++) {
			pres[i] = false;
		}
		bool done = false;
		for (int i=0; i<n; i++) {
			if (sets[i].size() < sq) continue;
			for (auto j: sets[i]) {
				pres[j] = true;
			}
			for (int j=0; j<n; j++) {
				if (i == j) continue;
				cnt = 0;
				for (auto k: sets[j]) {
					if (pres[k]) cnt++;
				}
				if (cnt > 1) {
					cout << i+1 << " " << j+1 << '\n';
					done = true;
					break;
				}
			}
			if (done) break;
			for (auto j: sets[i]) {
				pres[j] = false;
			}
		}
		if (done) continue;
		vector<int> inv[values.size()];
		for (int i=0; i<n; i++) {
			for (auto j: sets[i]) {
				inv[j].push_back(i);
			}
		}
		int last[values.size()], ind[values.size()];
		for (int i=0; i<values.size(); i++) {
			last[i] = ind[i] = -1;
		}
		for (int i=0; i<values.size(); i++) {
			for (auto j: inv[i]) {
				if (sets[j].size() > sq) continue;
				for (auto k: sets[j]) {
					if (k >= i) break;
					if (last[k] == i) {
						cout << ind[k]+1 << " " << j+1 << endl;
						done = true;
						break;
					}
					last[k] = i;
					ind[k] = j;
				}
				if (done) break;
			}
			if (done) break;
		}
		if (done) continue;
		cout << -1 << '\n';
	}
}