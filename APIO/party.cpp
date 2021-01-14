#include "party.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findUnusualGuest (int n, int m, int q) {
	vector<int> a, v, o;
	for (int i=0; i<n+m; i++) {
		v.push_back(i);
	}
	o = ask(v);
	for (int i=0; i<n+m; i++) {
		if (find(o.begin(), o.end(), i) == o.end()) return i;
	}
	bool flip = false;
	if (m < n) flip = true;
	if (flip) {
		for (int i=n; i<n+m; i++) {
			a.push_back(i);
		}
		swap(n, m);
	} else {
		for (int i=0; i<n; i++) {
			a.push_back(i);
		}
	}
	int l = 0, r = n-1, mid;
	while (l < r) {
		mid = (l+r)/2;
		v.clear();
		for (int i=l; i<=mid; i++) {
			v.push_back(a[i]);
		}
		o = ask(v);
		if (o.size() == mid-l+1) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	return a[l];
}