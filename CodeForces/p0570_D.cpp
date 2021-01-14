#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int id;
	int val;
	vector<int> adj;
	int depth;
	int in_t, out_t;
};
int n, m;
node graph[500100];
vector< pair<int, int> > layers[500100];
int timer = 0;
vector<int> presum[500100];
void dfs (int x, int p, int d) {
	graph[x].in_t = timer++;
	graph[x].depth = d;
	layers[d].push_back(make_pair(graph[x].in_t, x));
	for (auto i: graph[x].adj) {
		if (i != p) {
			dfs(i, x, d+1);
		}
	}
	graph[x].out_t = timer++;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=1; i<n; i++) {
		cin >> ai;
		ai--;
		graph[ai].adj.push_back(i);
		graph[i].adj.push_back(ai);
	}
	char ci;
	for (int i=0; i<n; i++) {
		graph[i].id = i;
		cin >> ci;
		graph[i].val = ci-'a';
	}
	dfs(0, 0, 1);
	for (int i=1; i<=n; i++) {
		if (layers[i].size() == 0) break;
		presum[i].push_back(0);
		for (int j=1; j<=layers[i].size(); j++) {
			presum[i].push_back(presum[i][j-1]);
			presum[i][j] ^= (1<<graph[layers[i][j-1].second].val);
		}
	}
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--;
		if (bi < graph[ai].depth || layers[bi].size() == 0) {
			cout << "Yes" << '\n';
			continue;
		}
		int start = lower_bound(layers[bi].begin(), layers[bi].end(), make_pair(graph[ai].in_t, ai))-layers[bi].begin();
		int end = lower_bound(layers[bi].begin(), layers[bi].end(), make_pair(graph[ai].out_t, ai))-layers[bi].begin()-1;
		if (end <= start) {
			cout << "Yes" << '\n';
			continue;
		}
		bool odd = false;
		bool pos = true;
		int res = presum[bi][end+1]^presum[bi][start];
		for (int j=0; j<26; j++) {
			if ((res & (1<<j)) > 0) {
				if (!odd) {
					odd = true;
				} else {
					pos = false;
					break;
				}
			}
		}
		if (pos) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}
}