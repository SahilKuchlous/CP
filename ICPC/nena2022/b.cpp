#include <iostream>
#include <vector>
#define MAXN 100005
using namespace std;
vector<int> adj[MAXN];
int perm[MAXN];
int anc[MAXN][4];

void dfs (int x, int p) {
	anc[x][0] = x;
	anc[x][1] = anc[p][0];
	anc[x][2] = anc[p][1];
	anc[x][3] = anc[p][2];
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}

bool close (int a, int b) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4-i; j++) {
			if (anc[a][i] == anc[b][j]) {
				return true;
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			adj[i].clear();
			perm[i] = 0;
			for (int j=0; j<4; j++) {
				anc[i][j] = 0;
			}
		}
		for (int i=0; i<n-1; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0, 0);
		for (int i=0; i<n; i++) {
			cin >> perm[i];
			perm[i]--;
		}
		bool ans = true;
		for (int i=0; i<n-1; i++) {
			// cout << perm[i] << " " << perm[i+1] << " " << close(perm[i], perm[i+1]) << endl;
			if (!close(perm[i], perm[i+1])) ans = false;
		}
		if (ans) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}