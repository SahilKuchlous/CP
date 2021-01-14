#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 100005
int n, m;
int s1, e1, s2, e2;
vector< pair<int, int> > adj[MAXN];
long long dist[3][MAXN];
set< pair<long long, int> > ord;
vector<int> topo;
vector<int> inc[MAXN];
vector<int> out[MAXN];
vector<int> opts;
bool vis[MAXN];
pair<long long, long long> dp1[MAXN], dp2[MAXN];
long long o;
void dijk (int x) {
	for (int i=0; i<n; i++) {
		dist[x][i] = 1e16;
	}
	int st = -1;
	if (x == 0) st = s1;
	if (x == 1) st = s2;
	if (x == 2) st = e2;
	dist[x][st] = 0;
	ord.insert(make_pair(0, st));
	while (ord.size() > 0) {
		int cur = ord.begin()->second;
		ord.erase(ord.begin());
		if (x == 0) topo.push_back(cur);
		for (auto i: adj[cur]) {
			if (dist[x][cur]+i.second < dist[x][i.first]) {
				ord.erase(make_pair(dist[x][i.first], i.first));
				dist[x][i.first] = dist[x][cur]+i.second;
				ord.insert(make_pair(dist[x][i.first], i.first));
				if (x == 0) inc[i.first] = {cur};
			} else if (dist[x][cur]+i.second == dist[x][i.first]) {
				if (x == 0) inc[i.first].push_back(cur);
			}
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s1 >> e1 >> s2 >> e2;
	s1--; e1--; s2--; e2--;
	int ai, bi, wi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> wi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, wi));
		adj[bi].push_back(make_pair(ai, wi));
	}
	dijk(0);
	dijk(1);
	dijk(2);
	for (int i=0; i<n; i++) {
		for (auto j: inc[i]) {
			out[j].push_back(i);
		}
	}
	opts = {e1};
	int ptr = 0;
	while (true) {
		if (ptr == opts.size()) break;
		vis[opts[ptr]] = true;
		for (auto i: inc[opts[ptr]]) {
			if (!vis[i]) opts.push_back(i);
		}
		ptr++;
	}
	for (auto i: topo) {
		if (!vis[i]) continue;
		dp1[i].first = dist[1][i];
		dp1[i].second = dist[2][i];
		for (auto j: inc[i]) {
			if (!vis[j]) continue;
			dp1[i].first = min(dp1[i].first, dp1[j].first);
			dp1[i].second = min(dp1[i].second, dp1[j].second);
		}
	}
	reverse(topo.begin(), topo.end());
	for (auto i: topo) {
		if (!vis[i]) continue;
		dp2[i].first = dist[1][i];
		dp2[i].second = dist[2][i];
		for (auto j: out[i]) {
			if (!vis[j]) continue;
			dp2[i].first = min(dp2[i].first, dp2[j].first);
			dp2[i].second = min(dp2[i].second, dp2[j].second);
		}
	}
	o = dist[1][e2];
	for (auto i: opts) {
		o = min(o, min(dp1[i].first+dp2[i].second, dp1[i].second+dp2[i].first));
	}
	cout << o << endl;
}