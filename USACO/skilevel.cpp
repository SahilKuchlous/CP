#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("skilevel.in");
ofstream fout("skilevel.out");
int n, m, t;
vector< pair< int, pair<int, int> > > edges;
vector<int> dsu[1000000];
int parent[1000000];
int cost[1000000];
void merge (int x, int y, int c) {
	int r1 = parent[x];
	int r2 = parent[y];
	if (r1 == r2) {
		return;
	}
	if (dsu[r1].size()+dsu[r2].size() >= t) {
		if (dsu[r1].size() < t) {
			for (auto i: dsu[r1]) {
				cost[i] = c;
			}
		}
		if (dsu[r2].size() < t) {
			for (auto i: dsu[r2]) {
				cost[i] = c;
			}
		}
	}
	if (dsu[r1].size() < dsu[r2].size()) {
		swap(r1, r2);
	}
	while (!dsu[r2].empty()) {
		int v = dsu[r2].back();
		dsu[r2].pop_back();
		parent[v] = r1;
		dsu[r1].push_back(v);
	}
}
int main () {
	fin >> n >> m >> t;
	int grid[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			fin >> grid[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i > 0) edges.push_back(make_pair(abs(grid[i][j]-grid[i-1][j]), make_pair(i*1000+j, (i-1)*1000+j)));
			if (j > 0) edges.push_back(make_pair(abs(grid[i][j]-grid[i][j-1]), make_pair(i*1000+j, i*1000+(j-1))));
		}
	}
	sort(edges.begin(), edges.end());
	for (int i=0; i<1000000; i++) {
		dsu[i] = {i};
		parent[i] = i;
	}
	for (auto i: edges) {
		merge(i.second.first, i.second.second, i.first);
	}
	long long o = 0;
	int stat;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			fin >> stat;
			if (stat == 1) o += cost[i*1000+j];
		}
	}
	fout << o << endl;
}