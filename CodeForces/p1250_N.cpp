#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map< int, vector< pair<int, int> > > adj;
map<int, bool> vis;
pair<int, int> dfs (int x) {
	vis[x] = true;
	pair<int, int> o = make_pair(adj[x][0].second, x);
	for (auto i: adj[x]) {
		if (!vis[i.first]) o = dfs(i.first);
	}
	return o;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		adj.clear();
		vis.clear();
		int n;
		cin >> n;
		int ai, bi;
		vector<int> points;
		for (int i=0; i<n; i++) {
			cin >> ai >> bi;
			points.push_back(ai);
			points.push_back(bi);
			adj[ai].push_back(make_pair(bi, i+1));
			adj[bi].push_back(make_pair(ai, i+1));
		}
		sort(points.begin(), points.end());
		points.resize(unique(points.begin(), points.end())-points.begin());
		vector< pair<int, int> > cng;
		dfs(points[0]);
		for (int i=1; i<points.size(); i++) {
			if (!vis[points[i]]) {
				pair<int, int> o = dfs(points[i]);
				cng.push_back(o);
			}
		}
		cout << cng.size() << endl;
		for (auto i: cng) {
			cout << i.first << " " << i.second << " " << points[0] << endl;
		}
	}
}