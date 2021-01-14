#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<int> adj[100100];
int md[100100];
void dfs1 (int x, int p) {
	md[x] = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
		md[x] = max(md[x], md[i]+1);
	}
}
int root;
bool vis[100100];
vector< pair<int, int> > cur;
vector<int> ord;
vector<int> moves;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai;
	for (int i=1; i<n; i++) {
		cin >> ai;
		adj[ai].push_back(i);
		adj[i].push_back(ai);
	}
	dfs1(0, 0);
	cur.push_back(make_pair(md[0], 0));
	while (cur.size() > 0) {
		root = cur[0].second;
		ord.push_back(root);
		vis[root] = true;
		for (int i=cur.size()-2; i>=0; i--) {
			moves.push_back(cur[i+1].second);
			adj[cur[i].second].push_back(cur[i+1].second);
			md[cur[i].second] = md[cur[i+1].second]+1;
		}
		cur.clear();
		for (auto i: adj[root]) {
			if (vis[i]) continue;
			cur.push_back(make_pair(md[i], i));
		}
		sort(cur.begin(), cur.end());
	}
	for (auto i: ord) cout << i << " ";
	cout << endl;
	cout << moves.size() << endl;
	reverse(moves.begin(), moves.end());
	for (auto i: moves) cout << i << " ";
	cout << endl;
	return 0;
}