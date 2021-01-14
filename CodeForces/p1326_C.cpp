#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	int a[n];
	int pos[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		pos[a[i]-1] = i;
	}
	vector<long long> v;
	long long o = 0;
	for (int i=0; i<k; i++) {
		o += n-i;
		v.push_back(pos[n-i-1]);
	}
	sort(v.begin(), v.end());
	long long dp[k];
	dp[0] = 1;
	for (int i=1; i<k; i++) {
		dp[i] = dp[i-1]*(v[i]-v[i-1]);
		dp[i] %= 998244353;
	}
	cout << o << " " << dp[k-1] << endl;
}