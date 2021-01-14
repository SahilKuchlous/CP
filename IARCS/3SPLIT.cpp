#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > t;
int n;

int dfs (int x, int l, int d[], int v[], int p[]) {
	p[x] = l;
	for (int i=0; i<t[x].size(); i++) {
		if (t[x][i] != l) {
			d[x] += dfs(t[x][i], x, d, v, p);
		}
	}
	d[x] += v[x];
	return d[x];
}

int main () {
	cin >> n;
	int v[n];
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	for (int i=0; i<n; i++) {
		vector<int> x;
		t.push_back(x);
	}
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	int o = INT_MAX;
	int d[n];
	int p[n];
	bool vis[n];
	vis[0] = true;
	for (int i=0; i<n; i++) {
		d[i] = 0;
	}
	dfs(0, -1, d, v, p);
	for (int i=1; i<n; i++) {
		for (int j=1; j<n; j++) {
			vis[i] = false;
		}
		int par = p[i];
		while (par != 0) {
			o = min(o, max(max(d[0]-d[par], d[par]-d[i]), d[i]));
			vis[par] = true;
			par = p[par];
		}
		for (int j=1; j<n; j++) {
			if (!vis[j]) {
				o = min(o, max(max(d[i], d[j]), d[0]-d[i]-d[j]));
			}
		}
	}
	cout << o << endl;
}