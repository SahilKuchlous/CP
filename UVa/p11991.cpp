#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main () {
	int n, m;
	while (cin >> n >> m) {
		map< int, vector<int> > v;
		int x;
		for (int i=0; i<n; i++) {
			cin >> x;
			if (v.find(x) == v.end()) {
				v[x] = vector<int> (1, i+1);
			} else {
				v[x].push_back(i+1);
			}
		}
		int l, k;
		for (int i=0; i<m; i++) {
			cin >> l >> k;
			if (v.find(k) == v.end() || v[k].size() < l) {
				cout << 0 << endl;
			} else {
				cout << v[k][l-1] << endl;
			}
		}
	}
}