#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	map< int, vector<int> > v_to_i;
	map<int, int> i_to_v;
	for (int i=0; i<n; i++) {
		v_to_i[a[i]].push_back(i);
		i_to_v[i] = a[i];
	}
	sort(a, a+n, greater<int>());
	int m;
	cin >> m;
	int k, p;
	vector<int> c;
	set<int> done;
	for (int i=0; i<m; i++) {
		cin >> k >> p;
		c.clear();
		done.clear();
		for (int j=0; j<k; j++) {
			int l = 1000000000;
			for (auto k: v_to_i[a[j]]) {
				if (k < l && done.find(k) == done.end()) {
					l = k;
				}
			}
			done.insert(l);
			c.push_back(l);
		}
		sort(c.begin(), c.end());
		cout << i_to_v[c[p-1]] << endl;
	}
}