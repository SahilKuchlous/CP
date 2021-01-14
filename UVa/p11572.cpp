#include <iostream>
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
		int o = 0;
		int s = 0;
		map<int, int> m;
		for (int i=0; i<n; i++) {
			if (m.find(a[i]) == m.end() || m[a[i]] == -1) {
				m[a[i]] = i;
			} else {
				for (int j=s; j<m[a[i]]; j++) {
					m[a[j]] = -1;
				}
				s = m[a[i]]+1;
				m[a[i]] = i;
			}
			if (i-s+1 > o) {
				o = i-s+1;
			}
			/*
			for (auto j: m) {
				cout << j.first << ", " << j.second << "; ";
			}
			cout << i-s+1 << endl;
			*/
		}
		cout << o << endl;
	}
}