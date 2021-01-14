#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		set<int> f1, f2, b1, b2;
		bool pos = true;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (b1.find(a[i]) == b1.end()) {
				b1.insert(a[i]);
			} else if (b2.find(a[i]) == b2.end()) {
				b2.insert(a[i]);
			} else {
				pos = false;
			}
		}
		if (!pos) {
			cout << 0 << endl;
			continue;
		}
		vector<int> o;
		for (int i=0; i<n-1; i++) {
			if (f1.find(a[i]) == f1.end()) {
				f1.insert(a[i]);
			} else {
				break;
			}
			if (b2.find(a[i]) != b2.end()) {
				b2.erase(a[i]);
			} else {
				b1.erase(a[i]);
			}
			if (b2.size() > 0) continue;
			if (f1.size() == i+1 && *(f1.begin()) == 1 && *prev(f1.end()) == i+1 && b1.size() == n-i-1 && *(b1.begin()) == 1 && *prev(b1.end()) == n-i-1) {
				o.push_back(i+1);
			}
		}
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i << " " << n-i << endl;
		}
	}
}