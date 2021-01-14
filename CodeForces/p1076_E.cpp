#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
long long presum[1000000];
vector<int> adj[1000000];
vector< pair<int, int> > upd[1000000];
long long val[1000000];
long long cur = 0;
void dfs (int x, int p, int h) {
	for (auto i: upd[x]) {
		presum[h] += i.second;
		if (h+i.first <= n) presum[h+i.first+1] -= i.second;
	}
	cur += presum[h];
	val[x] = cur;
	for (auto i: adj[x]) {
		if (i != p) dfs(i, x, h+1);
	}
	cur -= presum[h];
	for (auto i: upd[x]) {
		presum[h] -= i.second;
		if (h+i.first <= n) presum[h+i.first+1] += i.second;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	int m;
	cin >> m;
	int vi, di, xi;
	for (int i=0; i<m; i++) {
		cin >> vi >> di >> xi;
		upd[vi].push_back(make_pair(di, xi));
	}
	for (int i=0; i<3*n; i++) {
		presum[i] = 0;
	}
	dfs(1, 0, 0);
	for (int i=1; i<=n; i++) {
		cout << val[i] << " ";
	}
	cout << endl;
}