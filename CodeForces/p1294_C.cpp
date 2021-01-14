#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int f1 = 0;
		int end;
		for (int i=2; i<=(int)sqrt(n); i++) {
			if (n%i == 0) {
				f1 = i;
				n /= i;
				end = i;
				break;
			}
		}
		int f2 = 0, f3 = 0;
		for (int i=end+1; i<=(int)sqrt(n); i++) {
			if (n%i == 0 && n/i != i) {
				f2 = i;
				f3 = n/i;
				break;
			}
		}
		if (f1 == 0 || f2 == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << f1 << " " << f2 << " " << f3 << endl;
		}
	}
}