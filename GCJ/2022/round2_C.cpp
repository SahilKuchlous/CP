#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int n;
pair<long long, long long> pos_p[15];
pair<long long, long long> pos_c[15];
long long dist[15][15];
vector< pair<int, int> > ord;

long long calc_dist(int p, int c) {
	return (pos_p[p].first-pos_c[c].first)*(pos_p[p].first-pos_c[c].first) +
		(pos_p[p].second-pos_c[c].second)*(pos_p[p].second-pos_c[c].second);
}

bool solve(long long players, long long candies) {
	// cout << players << " " << candies << endl;
	if (players == (1ll<<n)-1) {
		return true;
	}
	for (int i=0; i<n; i++) {
		if ((players & (1ll<<i)) == 0) {
			int closest = -1;
			long long c_dist = -1;
			for (int j=0; j<n+1; j++) {
				if ((candies & (1ll << j)) == 0) {
					if (closest == -1 || dist[i][j] <= c_dist) {
						c_dist = dist[i][j];
						closest = j;
					}
				}
			}
			for (int j=1; j<n+1; j++) {
				if ((candies & (1ll << j)) == 0) {
					if (dist[i][j] <= c_dist) {
						ord.push_back(make_pair(i+1, j+1));
						if (solve(players|(1ll<<i), candies|(1ll<<j))) {
							return true;
						}
						ord.pop_back();
					}
				}
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		ord.clear();
		cout << "Case #" << test+1 << ": ";
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> pos_p[i].first >> pos_p[i].second;
		}
		for (int i=0; i<n+1; i++) {
			cin >> pos_c[i].first >> pos_c[i].second;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n+1; j++) {
				dist[i][j] = calc_dist(i, j);
			}
		}
		bool ans = solve(0, 0);
		if (ans) {
			cout << "POSSIBLE" << '\n';
			for (auto i: ord) {
				cout << i.first << " " << i.second << '\n';
			}
		} else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}