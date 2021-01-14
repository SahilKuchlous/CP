#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector< pair<int, int> > adj[500100];
bool done[500100];
bool vis[500100];
vector<int> hist;
void dfs (int x) {
	while (adj[x].size() > 0 && done[adj[x].back().second]) adj[x].pop_back();
	if (adj[x].size() == 0) return;
	vis[x] = true;
	hist.push_back(x);
	int cur = adj[x].back().first;
	if (vis[cur]) {
		while (hist.back() != cur) {
			cout << hist.back()+1 << " ";
			vis[hist.back()] = false;
			hist.pop_back();
		}
		cout << hist.back()+1 << '\n';
		vis[hist.back()] = false;
		hist.pop_back();
	}
	done[adj[x].back().second] = true;
	adj[x].pop_back();
	dfs(cur);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
	}
	for (int i=0; i<n; i++) {
		while (adj[i].size() > 0) {
			dfs(i);
		}
	}
}