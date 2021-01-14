#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> a[n];
		int freq[n+1];
		for (int i=0; i<n+1; i++) freq[i] = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i].first;
			a[i].second = i;
			freq[a[i].first]++;
		}
		sort(a, a+n);
		bool done = false;
		for (int i=0; i<n; i++) {
			if (freq[a[i].first] == 1) {
				cout << a[i].second+1 << endl;
				done = true;
				break;
			}
		}
		if (!done) cout << -1 << endl;
	}
}