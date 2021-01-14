#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 200005
int n;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> hist;
set<int> cycle;
bool done;
int grp[MAXN];
int sz[MAXN];
int cnt;
void init () {
	hist.clear();
	cycle.clear();
	done = false;
	cnt = 0;
	for (int i=0; i<n; i++) {
		adj[i].clear();
		vis[i] = false;
		sz[i] = 0;
	}
}
void dfs1 (int x, int p) {
	if (vis[x]) {
		while (true) {
			cycle.insert(hist.back());
			if (hist.back() == x) break;
			hist.pop_back();
		}
		done = true;
		return;
	}
	vis[x] = true;
	hist.push_back(x);
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
		if (done) return;
	}
	hist.pop_back();
}
void dfs2 (int x, int p) {
	grp[x] = cnt;
	sz[cnt]++;
	for (auto i: adj[x]) {
		if (i == p || cycle.find(i) != cycle.end()) continue;
		dfs2(i, x);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		int ai, bi;
		for (int i=0; i<n; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		dfs1(0, 0);
		for (auto i: cycle) {
			dfs2(i, i);
			cnt++;
		}
		long long o = 0;
		for (int i=0; i<n; i++) {
			o += sz[grp[i]]-1+2*(n-sz[grp[i]]);
		}
		o /= 2;
		cout << o << endl;
	}
}