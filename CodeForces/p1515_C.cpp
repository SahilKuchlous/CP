#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector< pair<int, int> > blocks;
		int h;
		for (int i=0; i<n; i++) {
			cin >> h;
			blocks.push_back(make_pair(-h, i));
		}
		sort(blocks.begin(), blocks.end());
		set< pair<int, int> > cols;
		for (int i=0; i<m; i++) {
			cols.insert(make_pair(0, i));
		}
		int o[n];
		for (int i=0; i<n; i++) {
			pair<int, int> top = *cols.begin();
			cols.erase(cols.begin());
			o[blocks[i].second] = top.second;
			top.first -= blocks[i].first;
			cols.insert(top);
		}
		if (prev(cols.end())->first - cols.begin()->first > x) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int i=0; i<n; i++) {
				cout << o[i]+1 << " ";
			}
			cout << endl;
		}
	}
}