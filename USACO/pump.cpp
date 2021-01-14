#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
ifstream fin("pump.in");
ofstream fout("pump.out");

int n, m;
int a, b;
map< int, set< pair<int, int> > > adj;
int cost[1010];
int flow[1010];
int max_f;

long long dijkstras (int min_f) {
	map<int, int> dist;
	priority_queue< pair<int, int> > best;
	best.push({0, 1});
	while (best.size() > 0) {
		pair<int, int> cur = best.top();
		// cout << cur.first << " " << cur.second << endl;
		best.pop();
		if (cur.second == n) {
			return dist[cur.second];
		}
		for (auto i: adj[cur.second]) {
			if (flow[i.second] >= min_f && (dist.find(i.first) == dist.end() || dist[i.first] > cur.first+cost[i.second])) {
				dist[i.first] = cur.first+cost[i.second];
				best.push({dist[i.first], i.first});
			}
		}
	}
	return -1;
}

int main () {
	fin >> n >> m;
	max_f = 0;
	for (int i=0; i<m; i++) {
		fin >> a >> b >> cost[i] >> flow[i];
		adj[a].insert({b, i});
		adj[b].insert({a, i});
		max_f = max(max_f, flow[i]);
	}
	long long o = -1;
	for (long long i=0; i<=max_f; i++) {
		long long c = dijkstras(i);
		if (c == -1) {
			break;
		}
		// cout << i << " " << c << endl;
		if (1e6*i/c > o) {
			o = 1e6*i/c;
		}
	}
	fout << o << endl;
}