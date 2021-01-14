#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> adj[100100];
vector<int> tour;
int timer = 0;
int in_t[100100];
int out_t[100100];
int depth[100100];
void dfs (int x, int p, int d) {
	tour.push_back(x);
	in_t[x] = timer++;
	depth[x] = d;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x, d+1);
			tour.push_back(x);
		}
	}
	out_t[x] = timer++;
}
int segtree[800100];
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x] = depth[tour[l]];
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return 1e8;
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	int o = 1e8;
	o = min(o, query(2*x+1, l, m, a, b));
	o = min(o, query(2*x+2, m+1, r, a, b));
	return o;
}
int dist (int a, int b) {
	if (in_t[a] > in_t[b]) {
		swap(a, b);
	}
	int lca_d = query(0, 0, tour.size()-1, in_t[a], in_t[b]);
	return depth[a]+depth[b]-2*lca_d;
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0, 1);
	create(0, 0, tour.size()-1);
	int q;
	cin >> q;
	int xi, yi, ki; 
	while (q--) {
		cin >> xi >> yi >> ai >> bi >> ki;
		xi--; yi--; ai--; bi--;
		int d1 = dist(ai, bi);
		int d2 = dist(ai, xi) + dist(bi, yi) + 1;
		int d3 = dist(ai, yi) + dist(bi, xi) + 1;
		if ((d1%2 == ki%2 && d1 <= ki) || (d2%2 == ki%2 && d2 <= ki) || (d3%2 == ki%2 && d3 <= ki)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}