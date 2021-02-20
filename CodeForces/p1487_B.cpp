#include <iostream>
using namespace std;
void solve () {
	long long n, k;
	cin >> n >> k;
	if (n%2 == 0) {
		cout << (k-1)%n+1 << endl;
	} else {
		cout << (k-1+(k-1)/(n/2))%n+1 << endl;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}