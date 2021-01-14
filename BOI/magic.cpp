#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	char a[n];
	int mc = 0;
	int o[m];
	int last = -1;
	bool pos = true;
	int cur = 0;
	int val[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] == '(') {
			val[i] = 1;
			cur++;
		}
		if (a[i] == ')') {
			val[i] = -1;
			cur--;
		}
		if (a[i] == ']') {
			if (mc < m-1) {
				o[mc] = 1;
				a[i] = ')';
				val[i] = -1;
				cur--;
			} else {
				last = i;
			}
			mc++;
		}
	}
	if (cur < 1) pos = false;
	if (last != -1) {
		o[m-1] = cur;
		val[last] = -cur;
	}
	cur = 0;
	for (int i=0; i<n; i++) {
		cur += val[i];
		if (cur < 0) {
			pos = false;
			break;
		}
	}
	if (pos) {
		cout << 1 << '\n';
		for (int i=0; i<m; i++) {
			cout << o[i] << '\n';
		}
	} else {
		cout << 0 << '\n';
	}
}