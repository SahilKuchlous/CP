#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		char a[n];
		set<int> l, r;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i] == '1') r.insert(i);
		}
		l.insert(-k-1);
		r.insert(n+k);
		int o = 0;
		for (int i=0; i<n; i++) {
			if (a[i] == '1') {
				r.erase(i);
				l.insert(i);
			} else {
				if (min(i-*prev(l.end()), *r.begin()-i) > k) {
					o++;
					l.insert(i);
				}
			}
		}
		cout << o << endl;
	}
}