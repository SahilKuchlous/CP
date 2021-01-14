#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=1; i<n; i++) {
			if (a[i] <= a[i-1]) a[i]++;
		}
		set<int> cur;
		for (int i=0; i<n; i++) {
			cur.insert(a[i]);
		}
		cout << cur.size() << endl;
	}
}