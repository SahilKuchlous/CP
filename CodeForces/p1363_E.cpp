#include <iostream>
#include <vector>
using namespace std;
int n;
int a[200100], b[200100], c[200100];
vector<int> adj[200100];
int t1[200100], t2[200100];
long long o = 0;
void dfs1 (int x, int p) {
	for (auto i: adj[x]) {
		if (i != p) {
			a[i] = min(a[i], a[x]);
			dfs1(i, x);
		}
	}
}
void dfs2 (int x, int p) {
	for (auto i: adj[x]) {
		if (i != p) {
			dfs2(i, x);
			t1[x] += t1[i];
			t2[x] += t2[i];
		}
	}
	if (b[x] == 1 && c[x] == 0) t1[x]++;
	if (b[x] == 0 && c[x] == 1) t2[x]++;
	int red = min(t1[x], t2[x]);
	o += 2ll*red*a[x];
	t1[x] -= red;
	t2[x] -= red;
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs1(0, 0);
	dfs2(0, 0);
	if (t1[0] == t2[0]) {
		cout << o << endl;
	} else {
		cout << -1 << endl;
	}
}