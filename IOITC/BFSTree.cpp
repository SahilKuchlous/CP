#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
vector<int> adj[1000100];
int tree[1000100];
vector<int> dag[1000100];
int inc[1000100];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		dag[i].clear();
		inc[i] = 0;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		reset();
		int ai, bi;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		for (int i=1; i<n; i++) {
			cin >> tree[i];
			tree[i]--;
		}
		bool o = true;
		for (auto i: adj[0]) {
			if (tree[i] != 0) o = false;
		}
		for (int i=0; i<n; i++) {
			if (tree[i] == 0) continue;
			for (auto j: adj[i]) {
				if (j == tree[i]) continue;
				dag[j].push_back(tree[i]);
				inc[tree[i]]++;
			}
		}
		set< pair<int, int> > s;
		for (int i=0; i<n; i++) {
			s.insert(make_pair(inc[i], i));
		}
		while (s.size() > 0) {
			pair<int, int> cur = *s.begin();
			s.erase(s.begin());
			if (cur.first > 0) {
				o = false;
				break;
			}
			for (auto i: dag[cur.second]) {
				if (s.find(make_pair(inc[i], i)) != s.end()) {
					s.erase(make_pair(inc[i], i));
					inc[i]--;
					s.insert(make_pair(inc[i], i));
				}
			}
		}
		cout << (o ? "YES":"NO") << endl;
	}
}