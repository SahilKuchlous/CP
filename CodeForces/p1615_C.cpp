#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char a[n], b[n];
		int cnt_a = 0, cnt_b = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i] == '1') {
				cnt_a++;
			}
		}
		for (int i=0; i<n; i++) {
			cin >> b[i];
			if (b[i] == '1') {
				cnt_b++;
			}
		}
		int o1 = -1, o2 = -1;
		if (cnt_a == cnt_b) {
			o1 = 0;
			for (int i=0; i<n; i++) {
				if (a[i] == '1' && b[i] != '1') {
					o1 += 2;
				}
			}
		}
		if (cnt_b == n-cnt_a+1) {
			o2 = 1;
			bool first = false;
			for (int i=0; i<n; i++) {
				if (a[i] == '1' && b[i] == '1') {
					if (!first) {
						first = true;
						continue;
					}
					o2 += 2;
				}
			}
		}
		if (o1 == -1 && o2 == -1) {
			cout << -1 << endl;
		} else if (o1 == -1) {
			cout << o2 << endl;
		} else if (o2 == -1) {
			cout << o1 << endl;
		} else {
			cout << min(o1, o2) << endl;
		}
	}
}