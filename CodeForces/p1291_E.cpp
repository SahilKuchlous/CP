#include <iostream>
#include <vector>
using namespace std;
int n, k;
int init[300100];
vector<int> edge[300100];
int par[300100];
int lft[300100], rt[300100];
int flip[300100];
int cost = 0;
void root (int x) {
	if (x == par[x]) return;
	root(par[x]);
	flip[x] ^= flip[par[x]];
	par[x] = par[par[x]];
}
void calc (int pos) {
	if (edge[pos].size() == 0) return;
	if (edge[pos].size() == 1) {
		int x = edge[pos][0];
		root(x);
		cost -= min(lft[par[x]], rt[par[x]]);
		if (init[pos] ^ flip[x]) {
			rt[par[x]] = 1e8;
		} else {
			lft[par[x]] = 1e8;
		}
		cost += min(lft[par[x]], rt[par[x]]);
		return;
	}
	int x = edge[pos][0];
	root(x);
	int y = edge[pos][1];
	root(y);
	if (par[x] == par[y]) return;
	cost -= min(lft[par[x]], rt[par[x]]);
	cost -= min(lft[par[y]], rt[par[y]]);
	if (init[pos] ^ flip[x] ^ flip[y]) {
		lft[par[x]] = min((int)1e8, lft[par[x]]+lft[par[y]]);
		rt[par[x]] = min((int)1e8, rt[par[x]]+rt[par[y]]);
	} else {
		lft[par[x]] = min((int)1e8, lft[par[x]]+rt[par[y]]);
		rt[par[x]] = min((int)1e8, rt[par[x]]+lft[par[y]]);
		flip[par[y]] = 1;
	}
	par[par[y]] = par[x];
	cost += min(lft[par[x]], rt[par[x]]);
}
int main () {
	cin >> n >> k;
	char inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		init[i] = inp-'0';
	}
	int c, x;
	for (int i=0; i<k; i++) {
		cin >> c;
		for (int j=0; j<c; j++) {
			cin >> x;
			x--;
			edge[x].push_back(i);
		}
		par[i] = i;
		lft[i] = 0;
		rt[i] = 1;
		flip[i] = 0;
	}
	for (int i=0; i<n; i++) {
		calc(i);
		cout << cost << endl;
	}
}