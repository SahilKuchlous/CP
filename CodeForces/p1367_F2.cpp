#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		vector< pair<int, int> > ord;
		for (int i=0; i<n; i++) {
			ord.push_back(make_pair(a[i], -i));
		}
		sort(ord.begin(), ord.end());
		set<int> cur;
		vector<int> extra;
		int bad = 0;
		int o = n-1;
		for (int i=0; i<n; i++) {
			while (bad < n && (cur.size() == 0 || ord[bad].second < *cur.begin())) {
				extra.push_back(ord[bad].second);
				if (bad == n-1 || ord[bad].first < ord[bad+1].first) {
					for (auto j: extra) cur.insert(j);
					extra.clear();
				}
				bad++;
			}
			o = min(o, n-bad+i);
			cur.erase(ord[i].second);
		}
		cout << o << endl;
	}
}