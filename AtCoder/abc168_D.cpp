#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	int par[n];
	for (int i=0; i<n; i++) {
		par[i] = -1;
	}
	queue<int> q;
	q.push(0);
	while (q.size() > 0) {
		int cur = q.front();
		q.pop();
		for (auto i: adj[cur]) {
			if (par[i] == -1) {
				par[i] = cur;
				q.push(i);
			}
		}
	}
	for (int i=1; i<n; i++) {
		if (par[i] == -1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for (int i=1; i<n; i++) {
		cout << par[i]+1 << endl;
	}
	return 0;
}