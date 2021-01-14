#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	set<int> vis;
	set<int> cur;
	int c = 0;
	vector<int> o;
	bool f = true;
	for (int i=0; i<n; i++) {
		c++;
		if (a[i] > 0) {
			if (vis.find(a[i]) != vis.end()) {
				f = false;
				break;
			}
			cur.insert(a[i]);
			vis.insert(a[i]);
		} else {
			if (cur.find(-a[i]) == cur.end()) {
				f = false;
				break;
			}
			cur.erase(-a[i]);
		}
		if (cur.size() == 0) {
			vis.clear();
			o.push_back(c);
			c = 0;
		}
	}
	if (cur.size() > 0) {
		f = false;
	}
	if (f) {
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i << " "; 
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}