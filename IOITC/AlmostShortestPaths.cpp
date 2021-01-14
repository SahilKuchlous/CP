#include <iostream>
#include <vector>
#include <queue>
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
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
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
	for (int i=0; i<n; i++) {
		cout << dp[i] << '\n';
	}
}
/*
9 13
1 2
2 3
3 1
1 4
4 5
5 6
6 7
8 7
4 8
4 6
5 8
4 9
9 1
*/