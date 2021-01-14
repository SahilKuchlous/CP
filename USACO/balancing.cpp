#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("balancing.in");
ofstream fout("balancing.out");
int n;
int segtree[2][400000];
int cur_i = 0;
void update (int x, int l, int r, int seg_i, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	segtree[seg_i][x] += v;
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, seg_i, p, v);
	update(2*x+2, m+1, r, seg_i, p, v);
}
int query (int x, int l, int r, int l1, int r1, int l2, int r2) {
	if (l == r) {
		(l1 < r1 ? l1 : r1) += segtree[0][x];
		(l2 < r2 ? l2 : r2) += segtree[1][x];
		return max(max(l1, r1), max(l2, r2));
	}
	int m = (l+r)/2;
	if (max(l1+segtree[0][2*x+1], l2+segtree[1][2*x+1]) < max(r1+segtree[0][2*x+2], r2+segtree[1][2*x+2])) {
		return query(2*x+2, m+1, r, l1+segtree[0][2*x+1], r1, l2+segtree[1][2*x+1], r2);
	} else {
		return query(2*x+1, l, m, l1, r1+segtree[0][2*x+2], l2, r2+segtree[1][2*x+2]);
	}
}
int main () {
	fin >> n;
	pair<int, int> pos[n];
	vector<int> x_pos;
	vector<int> y_pos;
	for (int i=0; i<n; i++) {
		fin >> pos[i].first >> pos[i].second;
		x_pos.push_back(pos[i].first);
		y_pos.push_back(pos[i].second);
	}
	sort(pos, pos+n);
	sort(x_pos.begin(), x_pos.end());
	x_pos.resize(unique(x_pos.begin(), x_pos.end())-x_pos.begin());
	sort(y_pos.begin(), y_pos.end());
	y_pos.resize(unique(y_pos.begin(), y_pos.end())-y_pos.begin());
	int act_pos;
	for (auto i: pos) {
		act_pos = lower_bound(y_pos.begin(), y_pos.end(), i.second)-y_pos.begin();
		update(0, 0, n-1, 1, act_pos, 1);
	}
	int o = 1000000;
	for (auto x: x_pos) {
		while (cur_i < n && pos[cur_i].first == x) {
			act_pos = lower_bound(y_pos.begin(), y_pos.end(), pos[cur_i].second)-y_pos.begin();
			update(0, 0, n-1, 0, act_pos, 1);
			update(0, 0, n-1, 1, act_pos, -1);
			cur_i++;
		}
		o = min(o, query(0, 0, n-1, 0, 0, 0, 0));
	}
	fout << o << endl;
}