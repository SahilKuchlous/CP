#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, b, h, w;
	while (cin >> n >> b >> h >> w) {
		int o = 500001;
		int p, a;
		for (int i=0; i<h; i++) {
			cin >> p;
			bool f = false;
			for (int j=0; j<w; j++) {
				cin >> a;
				if (a >= n) {
					f = true;
				}
			}
			if (p*n > b) {
				continue;
			}
			if (f) {
				o = min(o, p*n);
			}
		}
		if (o == 500001) {
			cout << "stay home" << endl;
		} else {
			cout << o << endl;
		}
	}
}