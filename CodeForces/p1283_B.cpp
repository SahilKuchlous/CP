#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a = n/k;
		if (n-k*a <= k/2) {
			cout << n << endl;
		} else {
			cout << (k+1)/2*a + k/2*(a+1) << endl;
		}
	}
}