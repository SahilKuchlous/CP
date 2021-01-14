#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool compEnd (pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first<b.first;
	}
	return a.second < b.second;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		pair<int, int> u[n];
		pair<int, int> d[n];
		for (int i=0; i<n; i++) {
			u[i].first = a[i].first;
			u[i].second = a[i].second;
			d[i].first = a[i].first;
			d[i].second = a[i].second;
		}
		sort(u, u+n);
		sort(d, d+n, compEnd);
		map< pair<int, int>, int > s;
		for (int i=0; i<n; i++) {
			s[a[i]] = 0;
		}
		for (int i=0; i<n; i++) {
			s[u[i]] += n-i-1;
			s[d[i]] += i;
		}
		for (int i=0; i<n; i++) {
			cout << s[a[i]] << " ";
		}
		cout << endl;
	}
}