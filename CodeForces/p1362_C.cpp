#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		int cnt = 0;
		for (int i=0; i<60; i++) {
			if (n & (1ll<<i)) cnt++;
		}
		cout << 2*n-cnt << endl;
	}
}