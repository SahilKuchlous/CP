#include <iostream>
#include <vector>
using namespace std;
int n;
vector< pair<int, int> > adj[110];
int dfs (int x, int p) {
	int o = 0;
	for (auto i: adj[x]) {
		if (i.first != p) {
			o = max(o, dfs(i.first, x)+i.second);
		}
	}
	return o;
}
int main () {
	cin >> n;
	int ai, bi, vi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi >> vi;
		adj[ai].push_back(make_pair(bi, vi));
		adj[bi].push_back(make_pair(ai, vi));
	}
	cout << dfs(0, 0) << endl;
}