#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 4005
int n, m;
int cost[MAXN];
vector<int> adj[MAXN];
vector<int> rev[MAXN];
bool vis[MAXN];
vector<int> topo;
vector< vector<int> > scc;
vector<int> cur;
void dfs1 (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs1(i);
	}
	topo.push_back(x);
}
void dfs2 (int x) {
	vis[x] = true;
	cur.push_back(x);
	for (auto i: rev[x]) {
		if (vis[i]) continue;
		dfs2(i);
	}
}
int label[MAXN];
int scc_cost[MAXN];
int scc_id[MAXN];
vector<int> adj_scc[MAXN];
vector<int> rev_scc[MAXN];
int cur_id = 0;
vector<int> peri[MAXN];
void dfs3 (int x) {
	vis[x] = true;
	if (adj_scc[x].size() == 0 || rev_scc[x].size() == 0) {
		peri[cur_id].push_back(x);
	}
	for (auto i: adj_scc[x]) {
		if (vis[i]) continue;
		dfs3(i);
	}
	for (auto i: rev_scc[x]) {
		if (vis[i]) continue;
		dfs3(i);
	}
}
int head_val[MAXN], head_id[MAXN];
int tail_val[MAXN], tail_id[MAXN];
long long o = 0;
vector< pair<int, int> > edges;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> cost[i];
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		rev[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		dfs1(i);
	}
	reverse(topo.begin(), topo.end());
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	for (auto i: topo) {
		if (vis[i]) continue;
		cur.clear();
		dfs2(i);
		scc.push_back(cur);
	}
	for (int i=0; i<scc.size(); i++) {
		scc_cost[i] = cost[scc[i][0]];
		scc_id[i] = scc[i][0];
		for (auto j: scc[i]) {
			label[j] = i;
			if (cost[j] < scc_cost[i]) {
				scc_cost[i] = cost[j];
				scc_id[i] = j;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (auto j: adj[i]) {
			if (label[i] == label[j]) continue;
			adj_scc[label[i]].push_back(label[j]);
			rev_scc[label[j]].push_back(label[i]);
		}
	}
	for (int i=0; i<scc.size(); i++) {
		sort(adj_scc[i].begin(), adj_scc[i].end());
		adj_scc[i].resize(unique(adj_scc[i].begin(), adj_scc[i].end())-adj_scc[i].begin());
		sort(rev_scc[i].begin(), rev_scc[i].end());
		rev_scc[i].resize(unique(rev_scc[i].begin(), rev_scc[i].end())-rev_scc[i].begin());
	}
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	for (int i=0; i<scc.size(); i++) {
		if (vis[i]) continue;
		dfs3(i);
		cur_id++;
	}
	for (int i=0; i<cur_id; i++) {
		head_val[i] = tail_val[i] = 1e9;
		for (auto j: peri[i]) {
			if (rev_scc[j].size() == 0 && scc_cost[j] <= head_val[i]) {
				head_val[i] = scc_cost[j];
				head_id[i] = scc_id[j];
			}
			if (adj_scc[j].size() == 0 && scc_cost[j] <= tail_val[i]) {
				tail_val[i] = scc_cost[j];
				tail_id[i] = scc_id[j];
			}
		}
	}
	for (int i=0; i<cur_id; i++) {
		for (auto j: peri[i]) {
			if (scc_id[j] == tail_id[i] || scc_id[j] == head_id[i]) continue;
			o += min(head_val[i], tail_val[i])+scc_cost[j];
			int node;
			if (head_val[i] < tail_val[i]) {
				node = head_id[i];
			} else {
				node = tail_id[i];
			}
			if (adj_scc[j].size() == 0) {
				edges.push_back(make_pair(scc_id[j], node));
			} else {
				edges.push_back(make_pair(node, scc_id[j]));
			}
		}
	}
	for (int i=0; i<cur_id-1; i++) {
		o += tail_val[i]+head_val[i+1];
		edges.push_back(make_pair(tail_id[i], head_id[i+1]));
	}
	if (head_id[cur_id-1] != tail_id[0]) {
		o += tail_val[cur_id-1]+head_val[0];
		edges.push_back(make_pair(tail_id[cur_id-1], head_id[0]));
	}
	cout << o << '\n';
	cout << edges.size() << '\n';
	for (auto i: edges) {
		cout << i.first+1 << " " << i.second+1 << '\n';
	}
}