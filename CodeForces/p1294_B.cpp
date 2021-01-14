#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pair<int, int> pkgs[n];
		for (int i=0; i<n; i++) {
			cin >> pkgs[i].first >> pkgs[i].second;
		}
		sort(pkgs, pkgs+n);
		string o;
		int pos = 0;
		int height = 0;
		for (auto i: pkgs) {
			if (height > i.second) {
				o = "F";
				break;
			}
			if (i.first > pos) {
				for (int j=pos; j<i.first; j++) {
					o += 'R';
				}
				pos = i.first;
			}
			for (int j=height; j<i.second; j++) {
				o += 'U';
			}
			height = max(height, i.second);
		}
		if (o == "F") {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << o << endl;
		}
	}
}