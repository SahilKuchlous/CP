#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream fin("rblock.in");
ofstream fout("rblock.out");
int n, m;
set< pair<int, int> > adj[300];
int dist[300];
bool vis[300];
set< pair<int, int> > ord;
bool inc[300];
int calc_dist (bool first) {
	ord.clear();
	for (int i=0; i<n; i++) {
		dist[i] = 1e9;
		vis[i] = false;
	}
	dist[0] = 0;
	ord.insert(make_pair(0, 0));
	pair<int, int> cur;
	while (true) {
		cur = *(ord.begin());
		if (first) inc[cur.second] = true;
		if (cur.second == n-1) {
			break;
		}
		ord.erase(ord.begin());
		vis[cur.second] = true;
		for (auto i: adj[cur.second]) {
			if (!vis[i.first] && cur.first+i.second < dist[i.first]) {
				ord.erase(make_pair(dist[i.first], i.first));
				dist[i.first] = cur.first+i.second;
				ord.insert(make_pair(dist[i.first], i.first));
			}
		}
	}
	return dist[n-1];
}
int main () {
	fin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		fin >> ai >> bi >> ci;
		ai--;
		bi--;
		adj[ai].insert(make_pair(bi, ci));
		adj[bi].insert(make_pair(ai, ci));
	}
	for (int i=0; i<n; i++) {
		inc[i] = false;
	}
	int org_dist = calc_dist(true);
	int new_dist = -1;
	for (int i=0; i<n; i++) {
		if (!inc[i]) continue;
		for (auto j: adj[i]) {
			if (!inc[j.first]) continue;
			adj[i].erase(j);
			adj[i].insert(make_pair(j.first, j.second*2));
			new_dist = max(new_dist, calc_dist(false));
			adj[i].erase(make_pair(j.first, j.second*2));
			adj[i].insert(j);
		}
	}
	fout << new_dist-org_dist << endl;
}