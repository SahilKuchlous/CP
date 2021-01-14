#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200005
int n, m;
set<int> adj[MAXN];
int par[MAXN];
vector<int> cc[MAXN];
set<int> cur;
vector<int> rem;
vector<int> o;
int root (int x) {
	while (x != par[x]) {
		par[x] = par[par[x]];
		x = par[x];
	}
	return x;
}
void merge (int a, int b) {
	int r1 = root(a), r2 = root(b);
	if (r1 == r2) return;
	if (cc[r1].size() < cc[r2].size()) swap(r1, r2);
	for (auto i: cc[r2]) {
		cc[r1].push_back(i);
	}
	par[r2] = r1;
	rem.push_back(r2);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	for (int i=0; i<n; i++) {
		par[i] = i;
		cc[i].push_back(i);
		cur.insert(i);
		for (auto j: cur) {
			for (auto k: cc[j]) {
				if (adj[i].find(k) != adj[i].end()) continue;
				merge(i, k);
				break;
			}
		}
		for (auto j: rem) cur.erase(j);
		rem.clear();
	}
	for (auto i: cur) {
		o.push_back(cc[i].size());
	}
	sort(o.begin(), o.end());
	cout << cur.size() << endl;
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}