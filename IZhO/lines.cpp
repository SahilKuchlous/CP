#include <iostream>
#include <set>
using namespace std;
int n;
int a[1000100], b[1000100];
multiset<int> cur;
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
		cur.insert(b[i]);
	}
	for (int i=0; i<n; i++) {
		if (a[i] > *cur.begin()) {
			cur.erase(cur.begin());
			cur.insert(a[i]);
			o++;
		}
		cur.erase(cur.begin());
	}
	cout << o << endl;
}