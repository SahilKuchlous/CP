#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n;
vector<int> adj[500005];
vector< pair<int, int> > o;
vector<int> dfs (int x, int p) {
	if (adj[x].size() == 1) return {x};
	vector<int> rem, cur;
	for (auto i: adj[x]) {
		if (i == p) continue;
		cur = dfs(i, x);
		for (auto j: cur) {
			rem.push_back(j);
		}
		if (rem.size() > 2) {
			o.push_back(make_pair(rem[0], rem.back()));
			rem.erase(rem.begin()); rem.pop_back();
		}
	}
	return rem;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	int root = 0;
	for (int i=0; i<n; i++) {
		if (adj[i].size() > 1) {
			root = i;
			break;
		}
	}
	vector<int> last = dfs(root, root);
	if (last.size() == 2) {
		o.push_back(make_pair(last[0], last[1]));
	} else if (last.size() == 1) {
		o.push_back(make_pair(last[0], root));
	}
	cout << o.size() << '\n';
	for (auto i: o) {
		cout << i.first+1 << " " << i.second+1 << '\n';
	}
	return 0;
}