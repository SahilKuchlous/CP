#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long p, q;
	cin >> p >> q;
	long long a, b, c, d;
	for (int i=0; i<q; i++) {
		cin >> a >> b >> c >> d;
		if ((a+b)%p != (c+d)%p) {
			cout << -1 << endl;
			continue;
		}
		if (a == c && b == d) {
			cout << 0 << endl;
			continue;
		}
		int x, y;
		int cnt = 0;
		while (true) {
			x = (2*a)%p;
			y = (b+p-a)%p;
			cnt++;
			if (c == x && d == y) {
				cout << cnt << endl;
				break;
			}
			a = x;
			b = y;
		}
	}
}