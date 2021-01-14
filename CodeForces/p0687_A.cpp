#include <iostream>
#include <set>
using namespace std;
int n, m;
set<int> adj[100100];
int grp[100100];
int c[2];
bool pos = true;
void dfs (int x, int p) {
	if (grp[x] > -1) {
		if (grp[x] != p) {
			pos = false;
		}
		return;
	}
	grp[x] = p;
	c[p]++;
	for (auto i: adj[x]) {
		dfs(i, (p+1)%2);
	}
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	for (int i=1; i<=n; i++) {
		grp[i] = -1;
	}
	for (int i=1; i<=n; i++) {
		if (grp[i] == -1) dfs(i, 0);
	}
	if (pos) {
		cout << c[0] << endl;
		for (int i=1; i<=n; i++) {
			if (grp[i] == 0) {
				cout << i << " ";
			}
		}
		cout << endl;
		cout << c[1] << endl;
		for (int i=1; i<=n; i++) {
			if (grp[i] == 1) {
				cout << i << " ";
			}
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}