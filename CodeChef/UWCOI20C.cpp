#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int h, w, q;
int grid[1010][1010];
vector< pair<int, pair<int, int> > > nodes;
vector< pair< pair<int, pair<int, int> >, int> > queries;
pair<int, int> par[1010][1010];
int size[1010][1010];
int ans[1000000];
pair<int, int> root (pair<int, int> x) {
	if (par[x.first][x.second] == make_pair(-1, -1)) {
		return par[x.first][x.second];
	}
	if (par[x.first][x.second] == x) {
		return x;
	}
	// par[x.first][x.second] = par[par[x.first][x.second].first][par[x.first][x.second].second];
	par[x.first][x.second] = root(par[x.first][x.second]);
	return par[x.first][x.second];
}
void merge (pair<int, int> a, pair<int, int> b) {
	if (par[a.first][a.second] != make_pair(-1, -1) && par[b.first][b.second] != make_pair(-1, -1)) {
		pair<int, int> r1 = root(b);
		pair<int, int> r2 = root(a);
		if (r1 != r2) {
			par[r2.first][r2.second] = r1;
			size[r1.first][r1.second] += size[r2.first][r2.second];
		}
	}
}
void add (pair<int, pair<int, int> > node) {
	int x = node.second.first;
	int y = node.second.second;
	par[x][y] = make_pair(x, y);
	size[x][y] = 1;
	if (x > 0) merge(make_pair(x, y), make_pair(x-1, y));
	if (x < h-1) merge(make_pair(x, y), make_pair(x+1, y));
	if (y > 0) merge(make_pair(x, y), make_pair(x, y-1));
	if (y < w-1) merge(make_pair(x, y), make_pair(x, y+1));
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w >> q;
		nodes.clear();
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				cin >> grid[i][j];
				nodes.push_back(make_pair(grid[i][j], make_pair(i, j)));
			}
		}
		sort(nodes.begin(), nodes.end());
		queries.clear();
		int ri, ci, qi;
		for (int i=0; i<q; i++) {
			cin >> ri >> ci >> qi;
			ri--;
			ci--;
			queries.push_back(make_pair(make_pair(qi, make_pair(ri, ci)), i));
		}
		sort(queries.begin(), queries.end());
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				par[i][j] = make_pair(-1, -1);
				size[i][j] = 0;
			}
		}
		int cur_q = 0;
		pair<int, int> r;
		for (auto node: nodes) {
			while (queries[cur_q].first.first <= node.first && cur_q < q) {
				r = root(queries[cur_q].first.second);
				if (r == make_pair(-1, -1)) {
					ans[queries[cur_q].second] = 0;
				} else {
					ans[queries[cur_q].second] = size[r.first][r.second];
				}
				cur_q++;
			}
			add(node);
		}
		for (int i=cur_q; i<q; i++) {
			ans[queries[i].second] = h*w;
		}
		for (int i=0; i<q; i++) {
			cout << ans[i] << endl;
		}
	}
}