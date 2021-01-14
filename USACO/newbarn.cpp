#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("newbarn.in");
ofstream fout("newbarn.out");
struct node {
	int id;
	vector<int> adj;
	bool vis = false;
	bool on = false;
	int size = 1;
	vector< pair<int, int> > parents;
	int height = 0, height2 = 0;
	int hchild = -1;
};
node nodes[100100];
int calc_size (int x, int p) {
	nodes[x].size = 1;
	for (auto i: nodes[x].adj) {
		if (i != p && !nodes[i].vis) {
			nodes[x].size += calc_size(i, x);
		}
	}
	return nodes[x].size;
}
int find_cent (int x, int p, int total) {
	for (auto i: nodes[x].adj) {
		if (i != p && !nodes[i].vis && 2*nodes[i].size >= total) {
			return find_cent(i, x, total);
		}
	}
	return x;
}
void update_parents (int x, int p, int root, int d) {
	nodes[x].parents.push_back(make_pair(root, d));
	for (auto i: nodes[x].adj) {
		if (i != p && !nodes[i].vis) {
			update_parents(i, x, root, d+1);
		}
	}
}
void cent_decomp (int x, int p) {
	calc_size(x, p);
	int root = find_cent(x, p, nodes[x].size);
	nodes[root].vis = true;
	update_parents(root, p, root, 0);
	for (auto i: nodes[root].adj) {
		if (i != p && !nodes[i].vis) {
			cent_decomp(i, root);
		}
	}
}
void update_heights (int x) {
	int prev = -1;
	for (int i=nodes[x].parents.size()-1; i>=0; i--) {
		node& par_node = nodes[nodes[x].parents[i].first];
		if (nodes[x].parents[i].second > par_node.height) {
			if (prev != par_node.hchild) par_node.height2 = par_node.height;
			par_node.height = nodes[x].parents[i].second;
			par_node.hchild = prev;
		} else if (nodes[x].parents[i].second > par_node.height2 && prev != par_node.hchild) {
			par_node.height2 = nodes[x].parents[i].second;
		}
		prev = nodes[x].parents[i].first;
	}
}
int query (int x) {
	int o = 0;
	int prev = -1;
	for (int i=nodes[x].parents.size()-1; i>=0; i--) {
		node& par_node = nodes[nodes[x].parents[i].first];
		if (par_node.on) {
			if (par_node.hchild == prev) {
				o = max(o, nodes[x].parents[i].second+par_node.height2);
			} else {
				o = max(o, nodes[x].parents[i].second+par_node.height);
			}
		}
		prev = nodes[x].parents[i].first;
	}
	return o;
}
int main () {
	int q;
	fin >> q;
	pair<char, int> inp[q];
	char ai;
	int bi;
	int n = 0;
	for (int i=0; i<q; i++) {
		fin >> ai >> bi;
		bi--;
		inp[i] = make_pair(ai, bi);
		if (ai == 'B') {
			nodes[n].id = n;
			if (bi > -2) {
				nodes[n].adj.push_back(bi);
				nodes[bi].adj.push_back(n);
			}
			n++;
		}
	}
	for (int i=0; i<n; i++) {
		if (!nodes[i].vis) {
			cent_decomp(i, -1);
		}
	}
	n = 0;
	for (int i=0; i<q; i++) {
		if (inp[i].first == 'B') {
			nodes[n].on = true;
			update_heights(n);
			n++;
		} else {
			fout << query(inp[i].second) << endl;
		}
	}
}