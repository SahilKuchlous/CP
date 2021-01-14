#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream fin("disrupt.in");
ofstream fout("disrupt.out");
struct node {
	int depth;
	int in_t, out_t;
	vector< pair<int, int> > tree;
	vector<int>	up;
	vector< pair<int, int> > down;
};
struct edge {
	int x, y;
	int weight;
	int lca;
};
node nodes[50100];
edge edges[50100];
vector<int> tour;
int cur_time = 0;
void dfs1 (int x, int p, int d) {
	tour.push_back(x);
	nodes[x].in_t = cur_time;
	nodes[x].depth = d;
	cur_time++;
	for (auto i: nodes[x].tree) {
		if (i.first != p) {
			dfs1(i.first, x, d+1);
			tour.push_back(x);
			cur_time++;
		}
	}
	nodes[x].out_t = cur_time-1;
}
pair<int, int> segtree[400100];
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x].first = tour[l];
		segtree[x].second = nodes[tour[l]].depth;
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	if (segtree[2*x+1].second < segtree[2*x+2].second) {
		segtree[x] = segtree[2*x+1];
	} else {
		segtree[x] = segtree[2*x+2];
	}
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return make_pair(-1, 1e8);
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	pair<int, int> p1 = query(2*x+1, l, m, a, b);
	pair<int, int> p2 = query(2*x+2, m+1, r, a, b);
	if (p1.second < p2.second) {
		return p1;
	} else {
		return p2;
	}
}
set< pair<int, int> > cur;
int o[100100];
void dfs2 (int x, int p, int e) {
	for (auto i: nodes[p].up) {
		if (edges[i].lca == p) continue;
		cur.erase(make_pair(edges[i].weight, i));
	}
	if (cur.size() == 0) {
		o[e] = -1;
	} else {
		o[e] = cur.begin()->first;
	}
	sort(nodes[x].down.begin(), nodes[x].down.end());
	int ind = 0;
	int init = 0;
	while (ind < nodes[x].down.size() && nodes[x].down[ind].first == nodes[x].in_t) {
		cur.insert(make_pair(edges[nodes[x].down[ind].second].weight, nodes[x].down[ind].second));
		ind++;
	}
	init = ind;
	for (auto i: nodes[x].tree) {
		if (i.first != p) {
			int si = ind;
			while (ind < nodes[x].down.size() && nodes[x].down[ind].first >= nodes[i.first].in_t && nodes[x].down[ind].first <= nodes[i.first].out_t) {
				cur.insert(make_pair(edges[nodes[x].down[ind].second].weight, nodes[x].down[ind].second));
				ind++;
			}
			int ei = ind;
			dfs2(i.first, x, i.second);
			for (int j=si; j<ei; j++) {
				cur.erase(make_pair(edges[nodes[x].down[j].second].weight, nodes[x].down[j].second));
			}
		}
	}
	for (int i=0; i<init; i++) {
		cur.erase(make_pair(edges[nodes[x].down[i].second].weight, nodes[x].down[i].second));
	}
	for (auto i: nodes[p].up) {
		if (edges[i].lca == p) continue;
		cur.insert(make_pair(edges[i].weight, i));
	}
}
int main () {
	int n, m;
	fin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		nodes[ai].tree.push_back(make_pair(bi, i));
		nodes[bi].tree.push_back(make_pair(ai, i));
	}
	dfs1(0, -1, 0);
	create(0, 0, tour.size()-1);
	for (int i=0; i<m; i++) {
		fin >> ai >> bi >> ci;
		ai--;
		bi--;
		if (nodes[ai].in_t > nodes[bi].in_t) swap(ai, bi);
		edges[i].x = ai;
		edges[i].y = bi;
		edges[i].weight = ci;
		edges[i].lca = query(0, 0, tour.size()-1, nodes[ai].in_t, nodes[bi].in_t).first;
		nodes[ai].up.push_back(i);
		nodes[bi].up.push_back(i);
		nodes[edges[i].lca].down.push_back(make_pair(nodes[ai].in_t, i));
		nodes[edges[i].lca].down.push_back(make_pair(nodes[bi].in_t, i));
	}
	dfs2(0, -1, -1);
	for (int i=0; i<n-1; i++) {
		fout << o[i] << endl;
	}
}