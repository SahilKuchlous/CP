#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> e, o;
		int inp;
		for (int i=1; i<=n; i++) {
			cin >> inp;
			if (inp%2 == 0) {
				e.push_back(i);
			} else {
				o.push_back(i);
			}
		}
		if (e.size() > 0) {
			cout << 1 << endl;
			cout << e[0] << endl;
		} else if (o.size() > 1) {
			cout << 2 << endl;
			cout << o[0] << " " << o[1] << endl;
		} else {
			cout << -1 << endl;
		}
	}
}