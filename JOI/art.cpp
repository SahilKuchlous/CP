#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500005
int n;
pair<long long, long long> a[MAXN];
long long dp[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	dp[0] = a[0].second;
	for (int i=1; i<n; i++) {
		dp[i] = a[i].second+max(0ll, dp[i-1]-a[i].first+a[i-1].first);
	}
	long long o = 0;
	for (int i=0; i<n; i++) {
		o = max(o, dp[i]);
	}
	cout << o << endl;
}