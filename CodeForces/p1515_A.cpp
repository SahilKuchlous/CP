#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		set<int> opts;
		for (int i=0; i<n; i++) {
			opts.insert(a[i]);
		}
		int ttl = 0;
		bool pos = true;
		vector<int> o;
		while (opts.size() > 0) {
			if (ttl+(*opts.begin()) == x) {
				if (opts.size() == 1) {
					pos = false;
					break;
				}
				ttl += *next(opts.begin());
				o.push_back(*next(opts.begin()));
				opts.erase(next(opts.begin()));
			} else {
				ttl += *opts.begin();
				o.push_back(*opts.begin());
				opts.erase(opts.begin());
			}
		}
		if (pos) {
			cout << "YES" << endl;
			for (auto i: o) {
				cout << i << " ";
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}