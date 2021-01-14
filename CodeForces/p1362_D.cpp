#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m;
vector<int> adj[500100];
int val[500100];
vector< pair<int, int> > ord;
bool done[500100];
bool pos = true;
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		cin >> val[i];
		ord.push_back(make_pair(val[i], i));
	}
	sort(ord.begin(), ord.end());
	for (auto i: ord) {
		set<int> nb;
		for (auto j: adj[i.second]) {
			if (done[j]) nb.insert(val[j]);
		}
		int act = 0;
		for (int j=1; j<=n; j++) {
			if (nb.find(j) == nb.end()) {
				act = j;
				break;
			}
		}
		if (act != i.first) {
			pos = false;
			break;
		}
		done[i.second] = true;
	}
	if (pos) {
		for (auto i: ord) cout << i.second+1 << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}