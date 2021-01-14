#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
vector<int> adj[5100];
long long total = 0, pairs = 0, sum = 0;
void dfs (int x, int p, int c, int d, vector< map<int, int> >& v) {
	v[c][d]++;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x, c, d+1, v);
		}
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
	for (int i=1; i<=n; i++) {
		vector< map<int, int> > depth( adj[i].size(), map<int, int>() );
		for (int j=0; j<adj[i].size(); j++) {
			dfs(adj[i][j], i, j, 1, depth);
		}
		for (int j=1; j<=n; j++) {
			pairs = sum = 0;
			int c = 0;
			for (int k=0; k<adj[i].size(); k++) {
				if (depth[k][j] > 0) c++;
				total += pairs*depth[k][j];
				pairs += sum*depth[k][j];
				sum += depth[k][j];
			}
			if (c < 3) break;
		}
	}
	cout << total << endl;
}