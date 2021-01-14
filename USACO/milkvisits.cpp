#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

vector<int> a;
vector< set<int> > adj(100001);
vector<int> path;
vector< vector<int> > counts( 100001, vector<int> (2, 0) );
int l, t;
vector<int> tin(100001);
vector<int> tout(100001);
vector< vector<int> > up;

void dfs (int node, int par) {
	counts[node][a[node]]++;
	tin[node] = ++t;
	up[node][0] = par;
	for (int i=1; i<=l; i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for (auto i: adj[node]) {
		if (i != par) {
			counts[i] = counts[node];
			dfs(i, node);
		}
	}
	tout[node] = ++t;
}

bool anc (int x, int y) {
	if (tin[x] <= tin[y] && tout[y] <= tout[x]) {
		return true;
	}
	return false;
}

int find_lca (int x, int y) {
	if (anc(x, y)) {
		return x;
	}
	if (anc(y, x)) {
		return y;
	}
	for (int i=l; i>=0; i--) {
		if (!anc(up[x][i], y)) {
			x = up[x][i];
		}
	}
	return up[x][0];
}

int main () {
	int n, m;
	fin >> n >> m;
	l = ceil(log2(n));
	string in;
	fin >> in;
	a.push_back(0);
	for (auto i: in) {
		if (i == 'G') {
			a.push_back(0);
		} else {
			a.push_back(1);
		}
	}
	int n1, n2;
	for (int i=0; i<n-1; i++) {
		fin >> n1 >> n2;
		adj[n1].insert(n2);
		adj[n2].insert(n1);
	}
	t = 0;
	up.assign(n+1, vector<int>(l+1));
	dfs(1, 1);
	int x, y;
	char c;
	string o = "";
	for (int i=0; i<m; i++) {
		fin >> x >> y >> c;
		int lca = find_lca(x, y);
		int cf;
		if (c == 'G') {
			cf = counts[x][0] + counts[y][0] - 2*counts[lca][0] + !a[lca];
		} else {
			cf = counts[x][1] + counts[y][1] - 2*counts[lca][1] + a[lca];
		}
		if (cf > 0) {
			o += "1";
		} else {
			o += "0";
		}
	}
	fout << o << endl;
}