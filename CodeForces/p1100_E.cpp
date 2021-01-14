#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n, m;
pair<int, int> edges[MAXN];
int wt[MAXN];
vector< pair<int, int> > adj[MAXN];
bool vis[MAXN];
bool hist[MAXN];
bool check (int x, int lim) {
	vis[x] = hist[x] = true;
	for (auto i: adj[x]) {
		if (i.second <= lim) continue;
		if (hist[i.first]) return false;
		if (vis[i.first]) continue;
		if (!check(i.first, lim)) return false;
	}
	hist[x] = false;
	return true;
}
int ord[MAXN];
int cnt = 0;
void dfs (int x, int lim) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (i.second <= lim) continue;
		if (vis[i.first]) continue;
		dfs(i.first, lim);
	}
	ord[x] = cnt++;
}
vector<int> o;
int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> edges[i].first >> edges[i].second >> wt[i];
		edges[i].first--; edges[i].second--;
		adj[edges[i].first].push_back(make_pair(edges[i].second, wt[i]));
	}
	int l = 0, r = 1e9, mid, best;
	while (l <= r) {
		mid = (l+r)/2;
		bool pos = true;
		for (int i=0; i<n; i++) {
			if (vis[i]) continue;
			if (!check(i, mid)) pos = false;
		}
		if (pos) {
			best = mid; r = mid-1;
		} else {
			l = mid+1;
		}
		for (int i=0; i<n; i++) {
			vis[i] = hist[i] = false;
		}
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) dfs(i, best);
	}
	for (int i=0; i<m; i++) {
		if (wt[i] > best) continue;
		if (ord[edges[i].first] < ord[edges[i].second]) o.push_back(i);
	}
	cout << best << " " << o.size() << endl;
	for (auto i: o) cout << i+1 << " ";
	cout << endl;
}