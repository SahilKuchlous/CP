#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 1000005
int n, s, t;
int a[MAXN];
vector< pair<int, long long> > adj[MAXN];
vector< pair<int, long long> > rev[MAXN];
bool vis[MAXN];
vector<int> topo;
long long dist[MAXN];
void dfs (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i.first]) continue;
		dfs(i.first);
	}
	topo.push_back(x);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	s--; t--;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector< pair<int, int> > ord;
	for (int i=0; i<n; i++) {
		while (ord.size() > 0 && a[i] <= ord.back().first) {
			ord.pop_back();
		}
		if (ord.size() > 0) adj[i].push_back(make_pair(ord.back().second, 1ll*a[i]*(i-ord.back().second)));
		ord.push_back(make_pair(a[i], i));
	}
	ord.clear();
	for (int i=n-1; i>=0; i--) {
		while (ord.size() > 0 && a[i] <= ord.back().first) {
			ord.pop_back();
		}
		if (ord.size() > 0) adj[i].push_back(make_pair(ord.back().second, 1ll*a[i]*(ord.back().second-i)));
		ord.push_back(make_pair(a[i], i));
	}
	for (int i=0; i<n; i++) {
		for (auto j: adj[i]) {
			rev[j.first].push_back(make_pair(i, j.second));
		}
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(topo.begin(), topo.end());
	for (int i=0; i<n; i++) {
		dist[i] = 1e16;
	}
	dist[s] = 0;
	for (auto i: topo) {
		for (auto j: rev[i]) {
			dist[i] = min(dist[i], dist[j.first]+j.second);
		}
	}
	long long o = 1e16;
	for (int i=0; i<n; i++) {
		o = min(o, dist[i]+1ll*a[i]*abs(i-t));
	}
	cout << o << endl;
}