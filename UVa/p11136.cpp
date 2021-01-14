#include <iostream>
#include <set>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		long long o = 0;
		int k, x;
		multiset<int> m;
		for (int i=0; i<n; i++) {
			cin >> k;
			for (int j=0; j<k; j++) {
				cin >> x;
				m.insert(x);
			}
			o += *(--m.end()) - *(m.begin());
			m.erase(m.begin());
			m.erase(--m.end());
		}
		cout << o << endl;
	}
}