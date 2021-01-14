#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100005
int n;
long long s;
vector< pair<int, int> > adj[MAXN];
int wt[MAXN];
int sz[MAXN];
set< pair<long long, int> > ord;
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		sz[i] = 0;
	}
	ord.clear();
}
void dfs (int x, int p) {
	bool leaf = true;
	for (auto i: adj[x]) {
		if (i.second == p) continue;
		leaf = false;
		dfs(i.first, i.second);
		if (p != -1) sz[p] += sz[i.second];
	}
	if (leaf) sz[p] = 1;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		reset();
		int ai, bi, wi;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi >> wi;
			ai--; bi--;
			adj[ai].push_back(make_pair(bi, i));
			adj[bi].push_back(make_pair(ai, i));
			wt[i] = wi;
		}
		dfs(0, -1);
		long long ttl = 0;
		for (int i=0; i<n-1; i++) {
			ttl += 1ll*sz[i]*wt[i];
			ord.insert(make_pair(1ll*sz[i]*(wt[i]/2)-1ll*sz[i]*wt[i], i));
		}
		int o = 0;
		while (ttl > s) {
			pair<long long, int> cur = *ord.begin();
			ord.erase(ord.begin());
			ttl += cur.first;
			o++;
			wt[cur.second] /= 2;
			ord.insert(make_pair(1ll*sz[cur.second]*(wt[cur.second]/2)-1ll*sz[cur.second]*wt[cur.second], cur.second));
		}
		cout << o << endl;
	}
}