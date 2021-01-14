#include <iostream>
#include <map>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		map<int, int> a;
		int x;
		for (int i=0; i<n; i++) {
			cin >> x;
			a[x] = i;
		}
		long long o = 0;
		int r = -1;
		for (int i=0; i<m; i++) {
			cin >> x;
			if (a[x] > r) {
				o += 2*(a[x]-i)+1;
				r = a[x];
			} else {
				o += 1;
			}
		}
		cout << o << endl;
	}
}