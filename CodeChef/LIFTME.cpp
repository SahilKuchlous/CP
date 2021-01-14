#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int p = 0;
		long long o = 0;
		int ai, bi;
		for (int i=0; i<q; i++) {
			cin >> ai >> bi;
			o += abs(p-ai)+abs(bi-ai);
			p = bi;
		}
		cout << o << endl;
	}
}