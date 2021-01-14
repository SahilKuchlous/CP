#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, m, d;
vector<int> adj[100100*50];
vector<int> rev[100100*50];
bool open[100100*50];
bool opt[100100*50];
vector<int> ord;
void topo (int x) {
	opt[x] = true;
	for (auto i: adj[x]) {
		if (opt[i]) continue;
		topo(i);
	}
	ord.push_back(x);
}
int cnt = 0;
vector<int> scc[100100*50];
int id[100100*50];
bool vis[100100*50];
void find (int x) {
	scc[cnt].push_back(x);
	id[x] = cnt;
	vis[x] = true;
	for (auto i: rev[x]) {
		if (!opt[i]) continue;
		if (vis[i]) continue;
		find(i);
	}
}
int dp[100100*50];
set<int> inc;
int ans = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> d;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		for (int j=0; j<d; j++) {
			adj[ai*50+j].push_back(bi*50+((j+1)%d));
			rev[bi*50+((j+1)%d)].push_back(ai*50+j);
		}
	}
	char ci;
	for (int i=0; i<n; i++) {
		for (int j=0; j<d; j++) {
			cin >> ci;
			open[i*50+j] = ci-'0';
		}
	}
	topo(0);
	reverse(ord.begin(), ord.end());
	for (auto i: ord) {
		if (!vis[i]) {
			find(i);
			cnt++;
		}
	}
	for (int i=0; i<cnt; i++) {
		inc.clear();
		for (auto j: scc[i]) {
			if (open[j]) inc.insert(j/50);
		}
		dp[i] = inc.size();
		inc.clear();
		for (auto j: scc[i]) {
			for (auto k: rev[j]) {
				if (opt[k] && id[k] != id[j]) inc.insert(id[k]);
			}
		}
		for (auto j: inc) {
			dp[i] += dp[j];
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}