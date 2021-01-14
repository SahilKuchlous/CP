#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v_cnt, s_cnt, q_cnt, root;
vector< pair<int, int> > adj[100100];
pair<int, int> edges[100100];
int wts[100100];
bool shop[100100];
int timer = 0;
int in_t[100100], out_t[100100];
int depth[100100];
long long subtree[100100];
void dfs1 (int x, int p) {
	in_t[x] = timer;
	timer++;
	if (p != x) depth[x] = depth[p]+1;
	subtree[x] = 1e16;
	if (shop[x]) subtree[x] = 0;
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		dfs1(i.first, x);
		subtree[x] = min(subtree[x], subtree[i.first]+wts[i.second]);
	}
	out_t[x] = timer-1;
}
int anc[100100][20];
long long sum[100100][20];
long long best[100100][20];
void dfs2 (int x, int p) {
	anc[x][0] = p;
	best[x][0] = min(subtree[x], sum[x][0]+subtree[p]);
	for (int i=1; i<20; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
		sum[x][i] = sum[x][i-1]+sum[anc[x][i-1]][i-1];
		best[x][i] = min(best[x][i-1], sum[x][i-1]+best[anc[x][i-1]][i-1]);
	}
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		sum[i.first][0] = wts[i.second];
		dfs2(i.first, x);
	}
}
long long solve (int x, int min_d) {
	long long ans = subtree[x];
	int cur = x;
	long long dist = 0;
	for (int i=19; i>=0; i--) {
		if (depth[cur]-(1<<i) >= min_d) {
			ans = min(ans, dist+best[cur][i]);
			dist += sum[cur][i];
			cur = anc[cur][i];
		}
	}
	return ans;
}
int main () {
	cin >> v_cnt >> s_cnt >> q_cnt >> root;
	root--;
	int ai, bi, ci;
	for (int i=0; i<v_cnt-1; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
		edges[i] = make_pair(ai, bi);
		wts[i] = ci;
	}
	for (int i=0; i<s_cnt; i++) {
		cin >> ai;
		ai--;
		shop[ai] = true;
	}
	depth[root] = 0;
	dfs1(root, root);
	dfs2(root, root);
	for (int i=0; i<v_cnt-1; i++) {
		if (depth[edges[i].first] > depth[edges[i].second]) swap(edges[i].first, edges[i].second);
	}
	for (int i=0; i<q_cnt; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		if (in_t[edges[ai].second] <= in_t[bi] && out_t[bi] <= out_t[edges[ai].second]) {
			long long ans = solve(bi, depth[edges[ai].second]);
			if (ans == 1e16) {
				cout << "oo" << endl;
			} else {
				cout << ans << endl;
			}
		} else {
			cout << "escaped" << endl;
		}
	}
}