#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int inp;
		set<int> vis;
		vector<int> o;
		for (int i=0; i<2*n; i++) {
			cin >> inp;
			if (vis.find(inp) == vis.end()) {
				o.push_back(inp);
				vis.insert(inp);
			}
		}
		for (auto i: o) cout << i << " ";
		cout << endl;
	}
}