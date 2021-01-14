#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n];
		int c = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		if (n == 2) {
			cout << -1 << endl;
			continue;
		}
		if (m < n) {
			cout << -1 << endl;
			continue;
		}
		vector< pair<int, int> > v;
		v.push_back(make_pair(1, n));
		c += a[0];
		c += a[n-1];
		for (int i=1; i<n; i++) {
			v.push_back(make_pair(i, i+1));
			c += a[i-1];
			c += a[i];
		}
		m -= n;
		int s1 = 100000, si1 = -1, s2 = 100000, si2 = -1;
		for (int i=0; i<n; i++) {
			if (a[i] < s1) {
				s2 = s1;
				si2 = si1;
				s1 = a[i];
				si1 = i;
			} else if (a[i] < s2) {
				s2 = a[i];
				si2 = i;
			}
		}
		while (m--) {
			v.push_back(make_pair(si1+1, si2+1));
			c += s1+s2;
		}
		cout << c << endl;
		for (auto i: v) {
			cout << i.first << " " << i.second << endl;
		}
	}
}