// At least k not exactly k.
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	int ti, ai, bi;
	set< pair<int, int> > opts[4];
	for (int i=0; i<n; i++) {
		cin >> ti >> ai >> bi;
		if (!ai && !bi) opts[0].insert({ti, i});
		if (ai && !bi) opts[1].insert({ti, i});
		if (!ai && bi) opts[2].insert({ti, i});
		if (ai && bi) opts[3].insert({ti, i});
	}
	bool pos = true;
	int ttl = 0;
	vector<int> o;
	while (m < 2*k) {
		if (opts[3].size() == 0) {
			pos = false;
			break;
		}
		ttl += opts[3].begin()->first;
		o.push_back(opts[3].begin()->second);
		opts[3].erase(opts[3].begin());
		m--; k--;
	}
	// Greedily sacrifice k - take either (1, 1) or (1, 0) and (0, 1)
	while (k > 0) {
		int s1 = 1e9;
		if (opts[3].size() > 0) {
			s1 = opts[3].begin()->first;
		}
		int s2 = 1e9;
		if (opts[1].size() > 0 && opts[2].size() > 0) {
			s2 = opts[1].begin()->first + opts[2].begin()->first;
		}
		if (s1 == 1e9 && s2 == 1e9) {
			pos = false;
			break;
		}

		if (s1 < s2) {
			
		}
	}
	// Greedily fill the rest of the remaining m books
	if (pos) {
		cout << ttl << endl;
		for (auto i: o) {
			cout << i+1 << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}