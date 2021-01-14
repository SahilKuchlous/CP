#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		k--;
		while (k--) {
			int min_d = 9, max_d = 0;
			for (long long i = n; i>0; i/=10) {
				min_d = min(min_d, (int)(i%10));
				max_d = max(max_d, (int)(i%10));
			}
			n += min_d*max_d;
			if (min_d == 0) break;
		}
		cout << n << endl;
	}
}