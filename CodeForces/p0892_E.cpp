#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
struct edge {
	int a, b;
	int wt;
};
edge org[500100];
vector<int> wts;
vector<int> edges[500100];
map< int, vector<int> > queries[500100];
int par[500100];
int size[500100];
stack< pair<int, int> > hist;
int root (int x) {
	while (x != par[x]) {
		x = par[x];
	}
	return x;
}
bool merge (int x, int y) {
	int r1 = root(x);
	int r2 = root(y);
	if (r1 == r2) {
		hist.push(make_pair(-1, -1));
		return false;
	}
	if (size[r1] > size[r2]) swap(r1, r2);
	par[r1] = r2;
	size[r2] += size[r1];
	hist.push(make_pair(r1, r2));
	return true;
}
void undo (int x, int y) {
	par[x] = x;
	size[y] -= size[x];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> org[i].a >> org[i].b >> org[i].wt;
		org[i].a--; org[i].b--;
		wts.push_back(org[i].wt);
	}
	sort(wts.begin(), wts.end());
	wts.resize(unique(wts.begin(), wts.end())-wts.begin());
	for (int i=0; i<m; i++) {
		edges[org[i].wt].push_back(i);
	}
	int q;
	cin >> q;
	int ci, vi;
	for (int i=0; i<q; i++) {
		cin >> ci;
		for (int j=0; j<ci; j++) {
			cin >> vi;
			vi--;
			queries[org[vi].wt][i].push_back(vi);
		}
	}
	bool o[q];
	for (int i=0; i<q; i++) {
		o[i] = true;
	}
	for (int i=0; i<n; i++) {
		par[i] = i;
		size[i] = 1;
	}
	for (auto i: wts) {
		for (auto &j: queries[i]) {
			for (auto k: j.second) {
				if (!merge(org[k].a, org[k].b)) {
					o[j.first] = false;
				}
			}
			for (int k=0; k<j.second.size(); k++) {
				pair<int, int> cur = hist.top();
				hist.pop();
				if (cur.first != -1) {
					undo(cur.first, cur.second);
				}
			}
		}
		for (auto j: edges[i]) {
			merge(org[j].a, org[j].b);
		}
	}
	for (int i=0; i<q; i++) {
		cout << (o[i] ? "YES":"NO") << '\n';
	}
}