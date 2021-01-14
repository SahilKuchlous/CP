#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
/*
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map< int, vector< vector<int> > > m;
		map< vector<int>, int > f;
		int l, r, v;
		for (int i=0; i<n; i++) {
			cin >> l >> r >> v;
			if (f.find({l, r}) == f.end()) {
				if (m.find(v) == m.end()) {
					m[v] = {{l, r}};
				} else {
					m[v].push_back({l, r});
				}
				f[{l, r}] = 1;
			} else {
				if (m.find(v) == m.end()) {
					m[v] = {{l, r, f[{l, r}]}};
				} else {
					m[v].push_back({l, r, f[{l, r}]});
				}
				f[{l, r}] += 1;
			}
		}
		map< vector<int>, set< vector<int> > > a;
		for (auto i: m) {
			vector< vector<int> > v = i.second;
			for (int j=0; j<v.size(); j++) {
				for (int k=j+1; k<v.size(); k++) {
					if ((v[j][0] <= v[k][0] && v[k][0] <= v[j][1]) || (v[j][0] <= v[k][1] && v[k][1] <= v[j][1])) {
						// cout << v[j].first << ", " << v[j].second << "; " << v[k].first << ", " << v[k].second << endl;
						if (a.find(v[j]) == a.end()) {
							a[v[j]] = {v[k]};
						} else {
							a[v[j]].insert(v[k]);
						}
						if (a.find(v[k]) == a.end()) {
							a[v[k]] = {v[j]};
						} else {
							a[v[k]].insert(v[j]);
						}
					} 
				}
			}
		}
		for (auto i: a) {
			cout << i.first[0] << ", " << i.first[1] << ": ";
			for (auto j: i.second) {
				cout << j[0] << ", " << j[1] << "; ";
			}
			cout << endl;
		}
		bool o = true;
		for (auto i: a) {
			for (auto j: i.second) {
				for (auto k: a[j]) {
					if (i.second.find(k) != i.second.end()) {
						o = false;
						break;
					}
				}
				if (!o) {
					break;
				}
			}
			if (!o) {
				break;
			}
		}
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
*/
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n][3];
		for (int i=0; i<n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		bool o = true;
		for (int i=0; i<n; i++) {
			int c = 0;
			for (int j=0; j<n; j++) {
				if (a[i][2] == a[j][2] && a[j][0] <= a[i][0] && a[j][1] >= a[i][0]) {
					c++;
				}
			}
			if (c > 2) {
				o = false;
				break;
			}
		}
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}