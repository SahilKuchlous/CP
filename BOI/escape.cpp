#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
ifstream fin("escape.in");
ofstream fout("escape.out");

int l, w, n;
vector< pair<long long, long long> > coor;
set<int> top;
set<int> bot;
set<int> vis;
vector< vector<int> > cc;
vector<int> cur;
map< int, vector<int> > adj;

void dfs (int v) {
	vis.insert(v);
	cur.push_back(v);
	for (auto i: adj[v]) {
		if (vis.find(i) == vis.end()) {
			dfs(i);
		}
	}
}

int main () {
	cin >> l >> w >> n;
	int x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		coor.push_back(make_pair(x, y));
		if (y+100 >= w) {
			top.insert(i);
		}
		if (y-100 <= 0) {
			bot.insert(i);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i != j && pow(coor[i].first-coor[j].first, 2) + pow(coor[i].second-coor[j].second, 2) <= 40000) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	while (vis.size() < n) {
		for (int i=0; i<n; i++) {
			if (vis.find(i) == vis.end()) {
				dfs(i);
				cc.push_back(cur);
				cur.clear();
			}
		}
	}
	bool out = true;
	bool has_top, has_bot;
	for (auto i: cc) {
		has_top = has_bot = false;
		for (auto j: i) {
			if (top.find(j) != top.end()) {
				has_top = true;
			}
			if (bot.find(j) != bot.end()) {
				has_bot = true;
			}
		}
		if (has_top && has_bot) {
			out = false;
			break;
		}
	}
	if (out) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
}