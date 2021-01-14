#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], ord[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ord[i] = a[i];
	}
	sort(ord, ord+n);
	map< int, set< pair<int, int> > > pos;
	for (int i=0; i<n; i++) {
		if (a[i] != ord[i]) {
			pos[ord[i]].insert(make_pair(a[i], i));
		}
	}
	bool f = true;
	vector< pair<int, int> > o;
	bool done[n];
	for (int i=0; i<n; i++) {
		done[i] = false;
	}
	for (int i=0; i<n; i++) {
		if (a[i] == ord[i] || done[i]) {
			continue;
		}
		if (pos[a[i]].size() == 0 || prev(pos[a[i]].end())->first < ord[i]) {
			f = false;
			break;
		}
		pair<int, int> opt = *pos[a[i]].lower_bound(make_pair(ord[i], -1));
		if (opt.first != ord[i]) {
			f = false;
			break;
		}
		o.push_back(make_pair(i, opt.second));
		pos[a[i]].erase(opt);
		pos[ord[i]].erase(make_pair(a[i], i));
		done[i] = true;
		done[opt.second] = true;
	}
	if (!f) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i.first+1 << " " << i.second+1 << endl;
	}
}