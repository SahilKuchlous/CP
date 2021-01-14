#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;
ifstream fin("shortcut.in");
ofstream fout("shortcut.out");
int n, m, t, in1, in2, in3;
int a[10100];
map< int, set<int> > adj;
map< pair<int, int>, int> wts;
int c[10100];
vector<int> path[10100];
pair<long long, int> dist[10100];
set<int> vis;
int main () {
	fin >> n >> m >> t;
	for (int i=1; i<=n; i++) {
		fin >> a[i];
	}
	for (int i=0; i<m; i++) {
		fin >> in1 >> in2 >> in3;
		adj[in1].insert(in2);
		adj[in2].insert(in1);
		wts[{in1, in2}] = wts[{in2, in1}] = in3;
	}
	dist[1] = {0, 0};
	for (int i=2; i<=n; i++) {
		dist[i] = {1e12, 0};
	}
	set< pair< pair<int, int>, int> > q;
	q.insert({{0, 0}, 1});
	path[1] = {1};
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (auto &i: adj[v]) {
			if (make_pair(dist[v].first+wts[{v, i}], v) < dist[i]) {
				q.erase({dist[i], i});
				dist[i] = {dist[v].first+wts[{v, i}], v};
				path[i] = path[v];
				path[i].push_back(i);
				q.insert({dist[i], i});
			}
		}
	}
	for (int i=1; i<=n; i++) {
		for (auto j: path[i]) {
			c[j] += a[i];
		}
	}
	long long o = 0;
	for (int i=1; i<=n; i++) {
		// cout << i << " " << c[i] << " " << dist[i].first-t << endl;
		o = max(o, (dist[i].first-t)*c[i]);
	}
	fout << o << endl;
}