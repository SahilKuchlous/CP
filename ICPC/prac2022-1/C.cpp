#include <iostream>
#include <set>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a;
	multiset<int> cur;
	for (int i=0; i<n; i++) {
		cin >> a;
		if (cur.find(a+1) != cur.end()) {
			cur.erase(cur.find(a+1));
		}
		cur.insert(a);
	}
	cout << cur.size() << endl;
}