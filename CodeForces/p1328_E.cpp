#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[200100];
int par[200100];
int height[200100];
int in[200100];
int out[200100];
int cur_time = 0;
int size;
vector< pair<int, int> > nodes;
void dfs (int x, int p, int h) {
	par[x] = p;
	height[x] = h;
	in[x] = cur_time;
	cur_time++;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x, h+1);
		}
	}
	out[x] = cur_time;
	cur_time++;
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0, 0);
	for (int i=0; i<m; i++) {
		cin >> size;
		nodes.clear();
		for (int j=0; j<size; j++) {
			cin >> ai;
			ai--;
			nodes.push_back(make_pair(height[par[ai]], par[ai]));
		}
		sort(nodes.begin(), nodes.end());
		bool o = true;
		for (int i=1; i<size; i++) {
			if (in[nodes[i].second] < in[nodes[i-1].second] || in[nodes[i].second] > out[nodes[i-1].second]) {
				o = false;
			}
		}
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
