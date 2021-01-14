#include <iostream>
#include <set>
using namespace std;
int main () {
	int x, n;
	cin >> x >> n;
	set<int> a;
	int inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		a.insert(inp);
	}
	for (int d=0; d<10000; d++) {
		if (a.find(x-d) == a.end()) {
			cout << x-d << endl;
			break;
		}
		if (a.find(x+d) == a.end()) {
			cout << x+d << endl;
			break;
		}
	}
}