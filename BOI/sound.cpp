#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, c;
	cin >> n >> m >> c;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	multiset<int> cur;
	vector<int> o;
	for (int i=0; i<m; i++) {
		cur.insert(a[i]);
	}
	if (*prev(cur.end())-*cur.begin() <= c) {
		o.push_back(0);
	}
	for (int i=1; i<=n-m; i++) {
		cur.erase(cur.find(a[i-1]));
		cur.insert(a[i+m-1]);
		if (*prev(cur.end())-*cur.begin() <= c) {
			o.push_back(i);
		}
	}
	if (o.size() == 0) {
		cout << "NONE" << '\n';
	} else {
		for (auto i: o) {
			cout << i+1 << '\n';
		}
	}
}