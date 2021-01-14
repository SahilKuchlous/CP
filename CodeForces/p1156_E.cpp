#include <iostream>
#include <set>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int pos[MAXN];
int par[MAXN];
set<int> grp[MAXN];
int o = 0;
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void calc (int x) {
	if (x == 0 || x == n-1 || a[x-1] > a[x] || a[x+1] > a[x]) return;
	int r1 = root(x-1), r2 = root(x+1);
	if (grp[r1].size() < grp[r2].size()) swap(r1, r2);
	for (auto i: grp[r2]) {
		if (grp[r1].find(a[x]-i) != grp[r1].end()) o++;
	}
}
void merge (int x, int y) {
	int r1 = root(x), r2 = root(y);
	if (r1 == r2) return;
	if (grp[r1].size() < grp[r2].size()) swap(r1, r2);
	for (auto i: grp[r2]) {
		grp[r1].insert(i);
	}
	par[r2] = r1;
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		pos[a[i]-1] = i;
	}
	for (int i=0; i<n; i++) {
		par[i] = i;
		grp[i].insert(a[i]);
	}
	for (int i=0; i<n; i++) {
		calc(pos[i]);
		if (pos[i] > 0 && a[pos[i]] > a[pos[i]-1]) merge(pos[i], pos[i]-1);
		if (pos[i] < n-1 && a[pos[i]] > a[pos[i]+1]) merge(pos[i], pos[i]+1);
	}
	cout << o << endl;
}