#include <iostream>
#include <algorithm>
using namespace std;
bool func (pair<int, int> x, pair<int, int> y) {
	return x.second > y.second;
}
int main () {
	int n, x, y, z;
	cin >> n;
	pair<int, int> a[n];
	for (int i=0; i<n; i++) {
		cin >> x >> y >> z;
		a[i] = make_pair(x, y+z);
	}
	sort(a, a+n, func);
	int s = 0;
	for (int i=0; i<n; i++) {
		s += a[i].first;
	}
	int t = s;
	int c = 0;
	for (int i=0; i<n; i++) {
		c += a[i].first;
		if (c + a[i].second > t) {
			t = c + a[i].second;
		}
	}
	cout << t << endl;
	return 0;
}