#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int q, d;
		cin >> q >> d;
		vector<int> opts;
		for (int i=0; i<10; i++) {
			opts.push_back(10*i+d);
			opts.push_back(10*d+i);
		}
		bool dp[100];
		for (int i=0; i<100; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for (auto i: opts) {
			for (int j=i; j<100; j++) {
				dp[j] |= dp[j-i];
			}
		}
		int n;
		for (int i=0; i<q; i++) {
			cin >> n;
			if (n >= 100) {
				cout << "YES" << endl;
				continue;
			}
			if (dp[n]) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}