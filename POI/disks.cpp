#include <iostream>
#include <set>
using namespace std;
int n, m;
long long a[300001], b[300001];
multiset<long long> cur;
int pos;
bool full = false;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cur.insert(a[i]);
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	pos = n-1;
	for (int i=0; i<m; i++) {
		while (*cur.begin() < b[i]) {
			if (pos < 0) {
				full = true;
				break;
			}
			cur.erase(cur.find(a[pos]));
			pos--;
		}
		if (pos < 0) {
			full = true;
			break;
		}
		cur.erase(cur.find(a[pos]));
		pos--;
	}
	if (full) {
		cout << 0 << endl;
		return 0;
	}
	cout << pos+2 << endl;
}