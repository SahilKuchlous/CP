#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	vector< pair<int, int> > v;
	int l, r;
	for (int i=0; i<n; i++) {
		cin >> l >> r;
		v.push_back(make_pair(l, -1));
		v.push_back(make_pair(r, 1));
	}
	sort(v.begin(), v.end());
	int c = 0;
	bool pos = true;
	for (int i=0; i<2*n; i++) {
		c -= v[i].second;
		if (c > 2) {
			pos = false;
		}
	}
	if (pos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}