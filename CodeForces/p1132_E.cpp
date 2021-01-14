#include <iostream>
#include <bitset>
using namespace std;
const int N = 8;
const int LCM = 840;
long long w;
long long a[N+1];
bitset<LCM> dp;
int main () {
	cin >> w;
	long long ttl = 0;
	for (int i=1; i<=N; i++) {
		cin >> a[i];
		ttl += a[i]*i;
	}
	if (ttl <= w) {
		cout << ttl << endl;
		return 0;
	}
	dp.reset();
	dp[0] = 1;
	for (int i=1; i<=N; i++) {
		for (int j=0; j<min(a[i], (long long)LCM/i); j++) {
			dp |= dp<<i;
		}
	}
	long long o = 0;
	for (int i=0; i<LCM; i++) {
		if (dp[i]) {
			int mod = (ttl-i)%LCM;
			long long cur = w - (w%LCM-mod+LCM)%LCM;
			o = max(o, cur);
		}
	}
	cout << o << endl;
}