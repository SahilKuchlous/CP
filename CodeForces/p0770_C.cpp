#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> adj[100100];
set<int> vis;
set<int> cur;
bool pos = true;
vector<int> ord;
void dfs (int x) {
	cur.insert(x);
	if (!pos) {
		return;
	}
	vis.insert(x);
	for (auto i: adj[x]) {
		if (cur.find(i) != cur.end()) {
			pos = false;
			return;
		}
		if (vis.find(i) == vis.end()) {
			dfs(i);
		}
	}
	cur.erase(x);
	ord.push_back(x);
}
int main () {
	int n, k;
	cin >> n >> k;
	int ess[k];
	for (int i=0; i<k; i++) {
		cin >> ess[i];
	}
	int c, x;
	for (int i=1; i<=n; i++) {
		cin >> c;
		for (int j=0; j<c; j++) {
			cin >> x;
			adj[i].insert(x);
		}
	}
	for (int i=0; i<k; i++) {
		if (vis.find(ess[i]) == vis.end()) dfs(ess[i]);
	}
	if (pos) {
		cout << ord.size() << endl;
		for (auto i: ord) {
			cout << i << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}