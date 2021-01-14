#include <iostream>
#include <map>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	long long c[n];
	for (int i=0; i<n; i++) c[i] = 0;
	map<int, int> m;
	for (int i=0; i<n; i++) {
		if (m.find(a[i]-i) == m.end()) {
			m[a[i]-i] = i;
			c[i] = a[i];
		} else {
			c[m[a[i]-i]] += a[i];
		}
	}
	long long o = 0;
	for (int i=0; i<n; i++) {
		o = max(o, c[i]);
	}
	cout << o << endl;
}