#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> adj[400100];
int m1[400100], m2[400100];
int o = 0;
void dfs (int x, int p) {
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		if (m1[i]-1 >= m1[x]) {
			m2[x] = m1[x];
			m1[x] = m1[i]-1;
		} else if (m1[i]-1 >= m2[x]) {
			m2[x] = m1[i]-1;
		}
	}
	o = max(o, m1[x] + m2[x] + (int)adj[x].size()-2);
	o = max(o, m1[x] + (int)adj[x].size()-1);
	m1[x] = max(m1[x]+adj[x].size()-1, adj[x].size());
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
	dfs(0, -1);
	cout << o << endl;
}