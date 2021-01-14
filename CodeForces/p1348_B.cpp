#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		set<int> s;
		int ai;
		for (int i=0; i<n; i++) {
			cin >> ai;
			s.insert(ai);
		}
		if (s.size() > k) {
			cout << -1 << endl;
			continue;
		}
		vector<int> v;
		for (auto i: s) {
			v.push_back(i);
		}
		while (v.size() < k) {
			v.push_back(1);
		}
		cout << n*k << endl;
		for (int i=0; i<n; i++) {
			for (auto j: v) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
}