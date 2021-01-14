#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int gcd (int a, int b) {
	if (a < b) swap(a, b);
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
int n, m;
bool grid[1010][1010];
bool vis[1010][1010];
void dfs (int i, int j) {
	if (vis[i][j]) return;
	vis[i][j] = true;
	if (j > 0 && grid[i][j-1]) dfs(i, j-1);
	if (j < m-1 && grid[i][j+1]) dfs(i, j+1);
	if (i > 0 && grid[i-1][j]) dfs(i-1, j);
	if (i < n-1 && grid[i+1][j]) dfs(i+1, j);
}
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	bool done = false;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!done && grid[i][j]) {
				dfs(i, j);
				done = true;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] & !vis[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	int prev_x[m];
	for (int i=0; i<m; i++) {
		prev_x[i] = -1;
	}
	int prev_y;
	vector<int> edges;
	map< pair<int, int>, int > cnt;
	for (int i=0; i<n; i++) {
		prev_y = -1;
		for (int j=0; j<m; j++) {
			if (!grid[i][j]) continue;
			bool l = (j > 0 && grid[i][j-1]);
			bool r = (j < m-1 && grid[i][j+1]);
			bool u = (i > 0 && grid[i-1][j]);
			bool d = (i < n-1 && grid[i+1][j]);
			if (!l & !r & !u & !d) {
				cout << -1 << endl;
				return 0;
			}
			if ((r^l) || (u^d) || (l&r&u&d)) {
				if (l) {
					edges.push_back(j-prev_y);
					cnt[{i, j}]++;
					cnt[{i, prev_y}]++;
				}
				if (u) {
					edges.push_back(i-prev_x[j]);
					cnt[{i, j}]++;
					cnt[{prev_x[j], j}]++;
				}
				prev_y = j;
				prev_x[j] = i;
			}
		}
	}
	if (edges.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (auto i: edges) {
		if (i == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	int oc = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (cnt.find({i, j}) != cnt.end() && cnt[{i, j}]%2 == 1) oc++;
		}
	}
	if (oc > 2) {
		cout << -1 << endl;
		return 0;
	}
	int cur = edges[0];
	for (int i=1; i<edges.size(); i++) {
		cur = gcd(cur, edges[i]);
	}
	vector<int> o;
	for (int i=2; i<=cur; i++) {
		if (cur%i == 0) o.push_back(i);
	}
	if (o.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}