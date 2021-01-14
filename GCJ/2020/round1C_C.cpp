#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		int n, d;
		cin >> n >> d;
		long long a[n];
		map<long long, int> freq;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			freq[a[i]]++;
		}
		int o = d-1;
		sort(a, a+n);
		for (int i=0; i<n; i++) {
			if (a[i] == a[n-1] && freq[a[i]] < d) continue;
			o = min(o, max(d-freq[a[i]], 0));
		}
		if (d == 3) {
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (2*a[i] == a[j]) {
						o = 1;
						break;
					}
				}
			}
		}
		cout << "Case #" << z << ": ";
		cout << o << endl;
	}
}