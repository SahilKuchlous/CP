#include <iostream>
#include <unordered_set>
using namespace std;
int rec (int d, unordered_set<int> v, int a[], int n) {
	v.insert(d);
	int o = 1;
	if (v.find(d-1) == v.end() && d > 0) {
		o += rec(d-1, v, a, n);
	}
	if (v.find(d+1) == v.end() && d < n-1) {
		o += rec(d+1, v, a, n);
	}
	if (a[d] == 2) {
		if (v.find(d-2) == v.end() && d > 1) {
			o += rec(d-2, v, a, n);
		}
		if (v.find(d+2) == v.end() && d < n-2) {
			o += rec(d+2, v, a, n);
		}
	}
	return o;
}
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		unordered_set<int> v;
		cout << rec(0, v, a, n) << endl;
	}
}