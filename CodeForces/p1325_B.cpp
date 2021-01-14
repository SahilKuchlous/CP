#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> s;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			s.insert(inp);
		}
		cout << s.size() << endl;
	}
}