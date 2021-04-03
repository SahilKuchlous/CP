#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	long long cost[n];
	for (int i=0; i<n; i++) {
		cin >> cost[i];
	}
	long long min_e = 1e9, min_o = 1e9;
	long long ttl_e = 0, ttl_o = 0;
	long long o = 1e16;
	for (int i=0; i<n; i++) {
		if (i%2 == 0) {
			min_e = min(min_e, cost[i]);
			ttl_e += cost[i];
		} else {
			min_o = min(min_o, cost[i]);
			ttl_o += cost[i];
		}
		if (i != 0) o = min(o, ttl_o+ttl_e+min_o*(n-(i+1)/2)+min_e*(n-(i+2)/2));
	}
	cout << o << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}