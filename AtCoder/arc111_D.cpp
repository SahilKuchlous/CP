#include <iostream>
#include <vector>
using namespace std;
#define MAXN 105
int n, m;
vector< pair< int, pair<int, int> > > adj[MAXN];
int val[MAXN];
bool vis[MAXN];
int type[MAXN*MAXN];
void dfs (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (val[i.first] < val[x]) {
			type[i.second.first] = i.second.second;
		} else if (val[i.first] > val[x]) {
			type[i.second.first] = -i.second.second;
		} else {
			if (type[i.second.first] == 0) type[i.second.first] = i.second.second;
			if (!vis[i.first]) dfs(i.first);
		}
	}
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, make_pair(i, 1)));
		adj[bi].push_back(make_pair(ai, make_pair(i, -1)));
	}
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		dfs(i);
	}
	for (int i=0; i<m; i++) {
		if (type[i] == 1) {
			cout << "->" << endl;
		} else {
			cout << "<-" << endl;
		}
	}
}
