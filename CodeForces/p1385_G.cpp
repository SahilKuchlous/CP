#include <iostream>
#include <vector>
using namespace std;
int n;
pair<int, int> p1[200100], p2[200100];
int freq[200100];
bool pos;
vector< pair<int, int> > adj[200100];
bool vis[200100];
int cnt;
vector<int> c[200100][2];
vector<int> o;
void reset () {
	pos = true;
	cnt = 0;
	o.clear();
	for (int i=0; i<n; i++) {
		freq[i] = 0;
		adj[i].clear();
		vis[i] = false;
		c[i][0].clear();
		c[i][1].clear();
	}
}
void dfs (int x, int col) {
	vis[x] = true;
	c[cnt][col].push_back(x);
	for (auto i: adj[x]) {
		if (vis[i.first]) continue;
		dfs(i.first, col^i.second);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		reset();
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			inp--;
			if (!pos) continue;
			if (freq[inp] == 2) {
				pos = false;
			}
			if (freq[inp] == 0) {
				p1[inp] = make_pair(0, i);
			} else {
				p2[inp] = make_pair(0, i);
			}
			freq[inp]++;
		}
		for (int i=0; i<n; i++) {
			cin >> inp;
			inp--;
			if (!pos) continue;
			if (freq[inp] == 2) {
				pos = false;
			}
			if (freq[inp] == 0) {
				p1[inp] = make_pair(1, i);
			} else {
				p2[inp] = make_pair(1, i);
			}
			freq[inp]++;
		}
		for (int i=0; i<n; i++) {
			if (freq[i] < 2) pos = false;
		}
		if (!pos) {
			cout << -1 << endl;
			continue;
		}
		for (int i=0; i<n; i++) {
			if (p1[i].second == p2[i].second) continue;
			adj[p1[i].second].push_back(make_pair(p2[i].second, p1[i].first == p2[i].first));
			adj[p2[i].second].push_back(make_pair(p1[i].second, p1[i].first == p2[i].first));
		}
		for (int i=0; i<n; i++) {
			if (adj[i].size() == 0) continue;
			if (!vis[i]) {
				dfs(i, 0);
				cnt++;
			}
		}
		for (int i=0; i<cnt; i++) {
			if (c[i][0].size() < c[i][1].size()) {
				for (auto j: c[i][0]) o.push_back(j);
			} else {
				for (auto j: c[i][1]) o.push_back(j);
			}
		}
		cout << o.size() << endl;
		for (auto i: o) cout << i+1 << " ";
		cout << endl;
	}
}