#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int m;
int rec (int e, int a[], set<int> t[]) {
	set<int> d;
	int o;
	d.insert(0);
	for (auto i : t[e]) {
		o = rec(i, a, t);
		d.insert(o + (a[e]-a[i]));
	}
	int me = *d.rbegin();
	if (me > m) {
		m = me;
	}
	return me;
}
int main () {
	int n;
	cin >> n;
	int a[n], p[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> p[i];
		p[i]--;
	}
	set<int> t[n];
	int h;
	for (int i=0; i<n; i++) {
		if (p[i] != -2) {
			t[p[i]].insert(i);
		} else {
			h = i;
		}
	}
	rec(h, a, t);
	cout << m << endl;
	return 0;
}