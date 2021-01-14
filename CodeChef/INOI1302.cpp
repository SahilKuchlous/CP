#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> v;
int rec (int n, set<int> a[], set<int> c, int k) {
	int o = 1;
	for (int i=0; i<n; i++) {
		if (v.count(i) == 0) {
			set<int> intersect;
			set_intersection(a[i].begin(), a[i].end(), c.begin(), c.end(), inserter(intersect, intersect.begin()));
			if (intersect.size() >= k) {
				v.insert(i);
				o += rec(n, a, a[i], k);
			}
		}
	}
	return o;
}
int main () {
	int n, k, p;
	cin >> n >> k;
	set<int> a[n];
	for (int i=0; i<n; i++) {
		cin >> p;
		set<int> s;
		int x;
		for (int j=0; j<p; j++) {
			cin >> x;
			s.insert(x);
		}
		a[i] = s;
	}
	set<int> c;
	v.insert(0);
	copy(a[0].begin(), a[0].end(), inserter(c, c.begin()));
	cout << rec(n, a, c, k) << endl;
	return 0;
}