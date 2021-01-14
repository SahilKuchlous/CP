#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n, x, y;
	cin >> n >> x >> y;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[n];
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	vector< pair<int, int> > v;
	for (int i=0; i<n; i++) {
		v.push_back(make_pair(b[i]-a[i], i));
	}
	sort(v.begin(), v.end());
	/*
	for (int i=0; i<n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	*/
	int i = 0;
	int s = 0;
	while (x > 0 && v[i].first <= 0) {
		s += a[v[i].second];
		i++;
		x--;
	}
	while (i < n) {
		s += b[v[i].second];
		i++;
	}
	cout << s << endl;
}