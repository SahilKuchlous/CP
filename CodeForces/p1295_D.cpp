#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long a, m;
		cin >> a >> m;
		long long g = gcd(a, m);
		int x = 2;
		long long mc = m;
		long long gc = g;
		set<int> banned;
		while (x <= ceil(sqrt(m*1.0))) {
			if (mc%x == 0) {
				mc /= x;
				if (gc%x == 0) {
					gc /= x;
				} else {
					banned.insert(x);
				}
			} else {
				x++;
			}
		}
		if (mc > 1 && gc%mc != 0) {
			banned.insert(mc);
		}
	}
}