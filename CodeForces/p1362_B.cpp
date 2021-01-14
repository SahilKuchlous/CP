#include <iostream>
#include <set>
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
		set<int> req;
		int o = -1;
		for (int i=1; i<=1024; i++) {
			for (int j=0; j<n; j++) {
				req.insert(a[j]);
			}
			for (int j=0; j<n; j++) {
				req.erase(a[j]^i);
			}
			if (req.size() == 0) {
				o = i;
				break;
			}
			req.clear();
		}
		cout << o << endl;
	}
}