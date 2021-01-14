#include <iostream>
#include <vector>
using namespace std;
int n, m;
int val[100100];
vector< pair<int, int> > adj[100100];
int depth[100100];
vector<int> hist;
bool cycle[100100];
bool found = false;
bool even = false;
void find (int x, int p) {
	depth[x] = depth[p]+1;
	hist.push_back(x);
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		if (depth[i.first] > 0) {
			found = true;
			if ((depth[x]-depth[i.first])%2 == 1) even = true;
			for (int j=0; j<=depth[x]-depth[i.first]; j++) {
				cycle[hist[hist.size()-j-1]] = true;
			}
			continue;
		}
		find(i.first, x);
	}
	hist.pop_back();
}
int o[100100];
bool vis[100100];
void dfs (int x, int p) {
	if (vis[x]) return;
	vis[x] = true;
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		dfs(i.first, x);
		if (!cycle[i.first]) {
			val[x] -= val[i.first];
			o[i.second] = val[i.first];
			val[i.first] = 0;
		}
	}
}
int dfs2 (int x, int p) {
	if (vis[x]) return val[x]/2;
	vis[x] = true;
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		if (cycle[i.first]) {
			val[i.first] -= val[x];
			o[i.second] = val[x];
			val[x] = 0;
			int shift = dfs2(i.first, x);
			o[i.second] += shift;
			return -shift;
		}
	}
	return 0;
}
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
	}
	if (m > n) {
		cout << 0 << endl;
		return 0;
	}
	find(0, 0);
	if (even) {
		cout << 0 << endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		if (cycle[i]) {
			dfs(i, i);
			for (int j=0; j<n; j++) vis[j] = false;
			dfs2(i, i);
			break;
		}
	}
	if (!found) dfs(0, 0);
	for (int i=0; i<m; i++) {
		cout << 2*o[i] << endl;
	}
}