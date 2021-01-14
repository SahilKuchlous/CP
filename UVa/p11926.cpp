#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
int main () {
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n==0 && m==0) {
			break;
		}
		bool c = true;
		bitset<1000001> v;
		int s, e;
		for (int i=0; i<n; i++) {
			cin >> s >> e;
			for (int j=s; j<e; j++) {
				if (!v.test(j)) {
					v.flip(j);
				} else {
					c = false;
					break;
				}
			}
			if (!c) {
				break;
			}
		}
		int x;
		for (int i=0; i<m; i++) {
			cin >> s >> e >> x;
			for (int j=s; j<=1000000; j+=x) {
				for (int k=j; k<min(1000001, j+(e-s)); k++) {
					if (!v.test(j)) {
						v.flip(j);
					} else {
						c = false;
						break;
					}
				}
				if (!c) {
					break;
				}
			}
			if (!c) {
				break;
			}
		}
		if (c) {
			cout << "NO CONFLICT" << endl;
		} else {
			cout << "CONFLICT" << endl;
		}
	}
}