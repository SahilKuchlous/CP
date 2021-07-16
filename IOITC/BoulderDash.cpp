#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 100005

int n, q;
vector<int> adj[MAXN];
int root;

int min_c[MAXN];
void dfs1 (int x, int p) {
	min_c[x] = x;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
		min_c[x] = min(min_c[x], min_c[i]);
	}
}

vector<int> ord;
int ind[MAXN];
int depth[MAXN];
int bin[MAXN][20];
void dfs2 (int x, int p) {
	depth[x] = depth[p]+1;
	bin[x][0] = p;
	for (int i=1; i<20; i++) {
		bin[x][i] = bin[bin[x][i-1]][i-1];
	}
	vector< pair<int, int> > temp;
	for (auto i: adj[x]) {
		if (i == p) continue;
		temp.push_back(make_pair(min_c[i], i));
	}
	sort(temp.begin(), temp.end());
	for (auto i: temp) {
		dfs2(i.second, x);
	}
	ind[x] = ord.size();
	ord.push_back(x);
}

priority_queue<int> empty;
int status[MAXN];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	int inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		if (inp == 0) {
			root = i;
			continue;
		}
		inp--;
		adj[i].push_back(inp);
		adj[inp].push_back(i);
	}
	dfs1(root, root);
	dfs2(root, root);
	for (int i=0; i<n; i++) {
		empty.push(-i);
	}
	int t, x;
	while (q--) {
		cin >> t >> x;
		if (t == 1) {
			for (int i=0; i<x; i++) {
				status[ord[-empty.top()]] = 1;
				if (i == x-1) cout << ord[-empty.top()]+1 << '\n';
				empty.pop();
			}
		} else {
			x--;
			int cur = x, ht = 0;
			for (int i=19; i>=0; i--) {
				if (status[bin[cur][i]]) {
					cur = bin[cur][i];
					ht += (1<<i);
				}
			}
			ht = min(ht, depth[x]-1);
			cout << ht << '\n';
			status[cur] = 0;
			empty.push(-ind[cur]);
		}
	}
}

/*
8 4
0 1 2 2 3 3 4 6 
1 8 
2 5 
2 7 
2 8
*/