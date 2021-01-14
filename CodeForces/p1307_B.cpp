#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		set<int> s;
		int a;
		for (int i=0; i<n; i++) {
			cin >> a;
			s.insert(a);
		}
		int o = 1e9;
		for (auto i: s) {
			if (x%i == 0) {
				o = min(o, x/i);
			} else if (i > x) {
				o = min(o, 2);
			} else {
				o = min(o, x/i+1);
			}
		}
		cout << o << endl;
	}
}