#include <iostream>
#include <set>
using namespace std;
int n;
long long a[200100];
set<int> adj[200100];
long long o = -1e13;
long long total[200100];
long long dfs (int x, int p) {
	long long b1 = -1e13, b2 = -1e13, c;
	total[x] = a[x];
	for (auto i: adj[x]) {
		if (i != p) {
			c = dfs(i, x);
			if (c > b1) {
				b2 = b1;
				b1 = c;
			} else if (c > b2) {
				b2 = c;
			}
			total[x] += total[i];
		}
	}
	if (b2 > -1e13) o = max(o, b1+b2);
	return max(b1, total[x]);
}
int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	dfs(1, 1);
	/*
	for (int i=1; i<=n; i++) {
		cout << total[i] << " ";
	}
	cout << endl;
	*/
	if (o > -1e13) {
		cout << o << endl;
	} else {
		cout << "Impossible" << endl;
	}
}