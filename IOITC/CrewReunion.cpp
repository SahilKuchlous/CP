#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define MAXN 100
#define MAXK 1000
int n, m, k;
int adj[MAXN][MAXK];
set< set<int> > vis;
bool pos = false;
vector<int> seq;
set<int> cur;
void reset () {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			adj[i][j] = -1;
		}
	}
	vis.clear();
	pos = false;
	seq.clear();
	cur.clear();
}
void dfs () {
	if (seq.size() > n*n*n) return;
	if (cur.size() == 1) {
		pos = true;
		return;
	}
	if (vis.find(cur) != vis.end()) return;
	vis.insert(cur);
	set<int> hist = cur;
	for (int i=0; i<k; i++) {
		seq.push_back(i);
		set<int> nxt;
		for (auto j: cur) {
			if (adj[j][i] == -1) {
				nxt.insert(j);
			} else {
				nxt.insert(adj[j][i]);
			}
		}
		cur = nxt;
		dfs();
		if (pos) return;
		seq.pop_back();
		cur = hist;
	}
}
void solve2 () {
	cin >> n >> m >> k;
	reset();
	int ui, vi, ci;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi >> ci;
		ui--; vi--; ci--;
		adj[ui][ci] = vi;
	}
	for (int i=0; i<n; i++) {
		cur.insert(i);
	}
	dfs();
	if (!pos) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	cout << seq.size() << " ";
	for (auto i: seq) {
		cout << i+1 << " ";
	}
	cout << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve2();
	}
}
/*
int n, m, k;
vector< pair<int, int> > adj[MAXN];
int root;
bool pos;
bool vis[MAXN];
bool hist[MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		vis[i] = false;
		hist[i] = false;
	}
	pos = true;
}
void dfs (int x) {
	if (hist[x]) pos = false;
	if (vis[x]) return;
	vis[x] = true;
	hist[x] = true;
	for (auto i: adj[x]) {
		dfs(i.first);
	}
	hist[x] = false;
}
void solve1 () {
	cin >> n >> m >> k;
	reset();
	int ui, vi, ci;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi >> ci;
		ui--; vi--;
		adj[ui].push_back(make_pair(vi, ci));
	}
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (adj[i].size() == 0) cnt++;
	}
	if (cnt != 1) pos = false;
	for (int i=0; i<n; i++) {
		dfs(i);
	}
	if (!pos) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	cout << n << " ";
	for (int i=0; i<n; i++) {
		cout << 1 << " ";
	}
	cout << endl;
}
vector< pair<int, int> > rev[MAXN];
void solve3 () {
	cin >> n >> m >> k;
	reset();
	int ui, vi, ci;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi >> ci;
		ui--; vi--;
		adj[ui].push_back(make_pair(vi, ci));
		rev[vi].push_back(make_pair(ui, ci));
	}
}
*/
/*
int n, m, k;
int adj[MAXN][MAXK];
int group[MAXN];
bool root[MAXN];
int edge[MAXN];
pair<int, int> path[MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		group[i] = i;
		root[i] = true;
		edge[i] = -1;
		for (int j=0; j<k; j++) {
			adj[i][k] = -1;
		}
	}
}
bool vis[MAXN];
void dfs (int x, int st, int col, int depth) {
	if (adj[x][col] == -1 || vis[x]) {
		if (x == st) return;
		group[st] = group[x];
		root[st] = false;
		edge[st] = x;
		path[st] = make_pair(col, depth);
	}
}
void solve () {
	cin >> n >> m >> k;
	reset();
	int ui, vi, ci;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi >> ci;
		ui--; vi--;
		adj[ui][ci] = vi;
	}
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			if (!root[j]) continue;
			for (int l=0; l<n; l++) {
				vis[l] = false;
			}
			dfs(j, j, i);
		}
	}
}
*/
/*
int n, m, k;
vector< pair<int, int> > adj[MAXN], rev[MAXN];
bool vis[MAXN];
vector<int> seq;
bool reach[MAXN][MAXN];
vector<int> path[MAXN][MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		rev[i].clear();
		for (int j=0; j<n; j++) {
			reach[i][j] = false;
			path[i][j].clear();
		}
	}
}
void dfs (int x, int st) {
	if (vis[x]) return;
	vis[x] = true;
	reach[st][x] = true;
	path[st][x] = seq;
	for (auto i: adj[x]) {
		seq.push_back(i.second);
		dfs(i.first, st);
		seq.pop_back();
	}
}
void solve3 () {
	cin >> n >> m >> k;
	reset();
	int ui, vi, ci;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi >> ci;
		ui--; vi--;
		adj[ui].push_back(make_pair(vi, ci));
		rev[vi].push_back(make_pair(ui, ci));
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			vis[j] = false;
		}
		dfs(i, i);
	}
	bool pos = false;
	vector<int> o;
	for (int i=0; i<n; i++) {
		bool flag = true;
		for (int j=0; j<n; j++) {
			if (!reach[j][i]) flag = false;
		}
		if (flag) {
			pos = true;
			for (int j=0; j<n; j++) {
				o.insert(o.end(), path[j][i].begin(), path[j][i].end());
			}
			break;
		}
	}
	if (!pos) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	cout << o.size() << " ";
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}
*/