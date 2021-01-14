#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
ifstream fin("moocast.in");
ofstream fout("moocast.out");

set< pair<int, int> > nvis;
vector< pair<int, int> > v;

void dfs (pair<int, int> p, int r) {
	nvis.erase(p);
	for (auto i: nvis) {
		if (pow(p.first-i.first, 2)+pow(p.second-i.second, 2) <= r) {
			dfs(i, r);
		}
	}
}

int main () {
	int n;
	fin >> n;
	int x, y;
	for (int i=0; i<n; i++) {
		fin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	int l = 0;
	int u = 1e9;
	int m;
	int o = 0;
	while (l <= u) {
		nvis.clear();
		for (auto i: v) {
			nvis.insert(i);
		}
		m = (l+u)/2;
		dfs(v[0], m);
		if (nvis.size() == 0) {
			o = m;
			u = m-1;
		} else {
			l = m+1;
		}
	}
	fout << o << endl;
}