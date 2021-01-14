#include <iostream>
#include <algorithm>
using namespace std;
struct block {
	int wt, st;
	long long val;
	bool operator < (const block &b) const {
		return wt+st < b.wt+b.st;
	}
};
int n;
block a[1010];
long long dp[20010];
long long o = 0;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].wt >> a[i].st >> a[i].val;
	}
	sort(a, a+n);
	for (int i=0; i<n; i++) {
		for (int j=min(a[i].st, 20005-a[i].wt); j>=0; j--) {
			dp[j+a[i].wt] = max(dp[j+a[i].wt], dp[j]+a[i].val);
			o = max(o, dp[j+a[i].wt]);
		}
	}
	cout << o << endl;
}