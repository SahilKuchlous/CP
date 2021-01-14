#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		set<int> a;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			a.insert(inp);
		}
		int o;
		for (int i=1; i<100000; i++) {
			if (a.find(i) == a.end()) {
				x--;
			}
			if (x == -1) {
				o = i-1;
				break;
			}
		}
		cout << o << endl;
	}
}