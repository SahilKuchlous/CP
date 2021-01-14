#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MAXN 500005
#define MOD 1000000007
int n, m;
vector<int> adj[MAXN];
queue<int> bfs;
int dist[MAXN];
long long cnt[MAXN];
bool vis[MAXN];
vector<int> ord;
long long dp[MAXN];
void generate (int sz) {
	srand(time(NULL));
	n = sz;
	for (int i=0; i<n; i++) {
		adj[i].clear();
	}
	set< pair<int, int> > inc;
	for (int i=1; i<sz; i++) {
		pair<int, int> edge = make_pair(rand()%i, i);
		while (edge.first == edge.second) edge = make_pair(rand()%i, i);
		adj[edge.first].push_back(edge.second);
		adj[edge.second].push_back(edge.first);
		inc.insert(edge);
	}
	for (int i=0; i<3*sz; i++) {
		pair<int, int> edge = make_pair(rand()%sz, rand()%sz);
		if (edge.first > edge.second) swap(edge.first, edge.second);
		if (edge.first == edge.second || inc.find(edge) != inc.end()) continue;
		adj[edge.first].push_back(edge.second);
		adj[edge.second].push_back(edge.first);
	}
}
vector<int> solve1 () {
	for (int i=0; i<n; i++) {
		dp[i] = 0;
		vis[i] = false;
		cnt[i] = 0;
	}
	ord.clear();
	bfs.push(0);
	cnt[0] = 1;
	vis[0] = true;
	while (bfs.size() > 0) {
		int cur = bfs.front();
		bfs.pop();
		for (auto i: adj[cur]) {
			if (!vis[i]) {
				vis[i] = true;
				dist[i] = dist[cur]+1;
				ord.push_back(i);
				bfs.push(i);
			}
			if (dist[i] == dist[cur]+1) {
				cnt[i] = (cnt[i]+cnt[cur])%MOD;
			}
		}
	}
	dp[0] = 1;
	for (auto i: ord) {
		for (auto j: adj[i]) {
			if (dist[j] == dist[i]) dp[i] = (dp[i]+cnt[j])%MOD;
			if (dist[j] == dist[i]-1) dp[i] = (dp[i]+dp[j])%MOD;
		}
	}
	vector<int> o;
	for (int i=0; i<n; i++) o.push_back(dp[i]);
	return o;
}
set<int> hist;
void dfs (int x) {
	hist.insert(x);
	if (hist.size()-1 <= dist[x]+1) dp[x] = (dp[x]+1)%MOD;
	for (auto i: adj[x]) {
		if (hist.find(i) != hist.end()) continue;
		dfs(i);
	}
	hist.erase(x);
}
vector<int> solve2 () {
	for (int i=0; i<n; i++) {
		dp[i] = 0;
	}
	bfs.push(0);
	while (bfs.size() > 0) {
		int cur = bfs.front();
		bfs.pop();
		for (auto i: adj[cur]) {
			if (!vis[i]) {
				vis[i] = true;
				dist[i] = dist[cur]+1;
				bfs.push(i);
			}
		}
	}
	dfs(0);
	vector<int> o;
	for (int i=0; i<n; i++) o.push_back(dp[i]);
	return o;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i=0; i<1000; i++) {
		generate(8);
		vector<int> v1 = solve1();
		vector<int> v2 = solve2();
		bool good = true;
		for (int i=0; i<n; i++) {
			if (v1[i] != v2[i]) {
				cout << v1[i] << " " << v2[i] << endl;
				good = false;
				break;
			}
		}
		if (!good) break;
		cout << "yes" << endl; 
	}
}