#include <iostream>
#include <set>
using namespace std;
int t, n;
int a[3000000];
multiset<int> cur;
int l, r;
int o = 1;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	l = 0; r = 1;
	cur.insert(a[0]);
	while (true) {
		if (*prev(cur.end()) - *cur.begin() > t) {
			cur.erase(cur.find(a[l]));
			l++;
		} else {
			o = max(o, r-l);
			if (r >= n) break;
			cur.insert(a[r]);
			r++;
		}
	}
	cout << o << endl;
}