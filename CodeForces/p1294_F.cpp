#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector<int> adj[200100];
int ptr[200100];
vector<int> path[200100];
void dfs (int x, int p) {
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		if (path[ptr[i]].size() > path[ptr[x]].size()) ptr[x] = ptr[i];
	}
	path[ptr[x]].push_back(x);
}
vector<int> diam;
queue< pair<int, int> > bfs;
bool vis[200100];
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		ptr[i] = i;
	}
	dfs(0, 0);
	int p1 = path[ptr[0]][0];
	for (int i=0; i<n; i++) {
		ptr[i] = i;
		path[i].clear();
	}
	dfs(p1, p1);
	diam = path[ptr[p1]];
	bfs.push(make_pair(diam[0], 0));
	bfs.push(make_pair(diam.back(), 0));
	vis[diam[0]] = vis[diam.back()] = true;
	for (int i=1; i<diam.size()-1; i++) {
		bfs.push(make_pair(diam[i], 0));
		vis[diam[i]] = true;
	}
	pair<int, int> cur;
	while (bfs.size() > 0) {
		cur = bfs.front();
		bfs.pop();
		for (auto i: adj[cur.first]) {
			if (vis[i]) continue;
			bfs.push(make_pair(i, cur.second+1));
			vis[i] = true;
		}
	}
	cout << diam.size()+cur.second-1 << endl;
	cout << diam[0]+1 << " " << diam.back()+1 << " " << cur.first+1 << endl;
}