#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> *paths;
bool *visited;
int *mus;
void dps (int x, int &mc) {
	visited[x] = true;
	mc += mus[x];
	for (auto i : paths[x]) {
		if (!visited[i]) {
			dps(i, mc);
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, n, m, k;
	cin >> t;
	for (int z=0; z<t; z++) {
		cin >> n >> m >> k;
		mus = new int[n];
		vector<int> grps;
		paths = new vector<int>[n];
		int a, b;
		for (int i=0; i<m; i++) {
			cin >> a >> b;
			a--;
			b--;
			paths[a].push_back(b);
			paths[b].push_back(a);
		}
		for (int i=0; i<n; i++) {
			cin >> mus[i];
		}
		visited = new bool[n];
		for (int i=0; i<n; i++) {
			visited[i] = false;
		}
		int mc = 0;
		for (int i=0; i<n; i++) {
			if (!visited[i]) {
				dps(i, mc);
				grps.push_back(mc);
				mc = 0;
			}
		}
		if (k > grps.size()) {
			cout << -1 << '\n';
			continue;
		}
		sort(grps.begin(), grps.end());
		int o = 0;
		int ln = grps.size();
		for (int i=0; i<k; i++) {
			if (i%2 == 0) {
				o += grps[ln-i/2-1];
			} else {
				o += grps[(i-1)/2];
			}
		}
		cout << o << '\n';
	}
	return 0;
}