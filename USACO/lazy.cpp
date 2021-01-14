#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
ifstream fin("lazy.in");
ofstream fout("lazy.out");
int n, k;
struct interval {
	int x, top, bot, g;
};
vector<interval> intervals;
bool comp (const interval a, const interval b) {
	return a.x < b.x;
}
vector<int> coords;
map<int, int> ind;
int segtree[600000];
int lazy[600000];
void update (int x, int l, int r, int a, int b, int v) {
	if (lazy[x] != 0) {
		segtree[x] += lazy[x];
		if (l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	}
	if (r < a || b < l) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[x] = v;
		segtree[x] += lazy[x];
		if (l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
		return;
	}

	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
int main () {
	fin >> n >> k;
	int gi, xi, yi;
	for (int i=0; i<n; i++) {
		fin >> gi >> xi >> yi;
		interval start, end;
		start.x = 2*(xi-yi-k)-1;
		end.x = 2*(xi-yi+k)+1;
		start.top = end.top = 2*(xi+yi+k)+1;
		start.bot = end.bot = 2*(xi+yi-k)-1;
		coords.push_back(start.top);
		coords.push_back(start.bot);
		start.g = gi;
		end.g = -gi;
		intervals.push_back(start);
		intervals.push_back(end);
	}
	sort(intervals.begin(), intervals.end(), comp);
	coords.resize(unique(coords.begin(), coords.end()) - coords.begin());
	sort(coords.begin(), coords.end());
	for (int i=0; i<coords.size(); i++) {
		ind[coords[i]] = i;
	}
	for (int i=0; i<2*coords.size()+1; i++) {
		segtree[i] = lazy[i] = 0;
	}
	int o = 0;
	for (int i=0; i<intervals.size(); i++) {
		update(0, 0, coords.size()-1, ind[intervals[i].bot], ind[intervals[i].top], intervals[i].g);
		if (i != intervals.size()-1 && intervals[i].x == intervals[i+1].x) {
			continue;
		}
		o = max(o, segtree[0]);
	}
	fout << o << endl;
}