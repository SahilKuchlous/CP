#include <iostream>
#include <set>
using namespace std;
int n;
set<int> adj[100100];
long long odd = 0, even = 0;
set<int> vis;
void dfs (int x, int d) {
	vis.insert(x);
	if (d%2 == 0) {
		even++;
	} else {
		odd++;
	}
	for (auto i: adj[x]) {
		if (vis.find(i) == vis.end()) {
			dfs(i, d+1);
		}
	}
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	dfs(1, 0);
	cout << odd*even-n+1 << endl;
}