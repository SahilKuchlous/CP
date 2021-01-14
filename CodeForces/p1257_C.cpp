#include <iostream>
#include <vector>
#include <map>
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
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		map< int, vector<int> > m;
		for (int i=0; i<n; i++) {
			m[a[i]].push_back(i);
		}
		int o = 1000000;
		for (auto i: m) {
			for (int j=0; j<i.second.size()-1; j++) {
				if (i.second[j+1]-i.second[j] < o) {
					o = i.second[j+1]-i.second[j];
				}
			}
		}
		if (o < 1000000) {
			cout << o+1 << endl;
		} else {
			cout << -1 << endl;
		}
	}
}