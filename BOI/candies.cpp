#include <iostream>
#include <bitset>
using namespace std;
#define MAXN 105
#define MAXM 7005
#define MOD 1000000007
int n;
int a[MAXN];
int ttl = 0;
long long dp1[MAXN*MAXM];
bitset<4*MAXN*MAXM> dp2;
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ttl += a[i];
	}
	dp1[0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=ttl; j>=a[i]; j--) {
			dp1[j] = (dp1[j]+dp1[j-a[i]])%MOD;
		}
	}
	int cnt = -1, val = -1;
	for (int i=0; i<n; i++) {
		for (int j=a[i]; j<=ttl; j++) {
			dp1[j] = (dp1[j]-dp1[j-a[i]]+MOD)%MOD;
		}
		int cur = 0;
		for (int j=0; j<=ttl; j++) {
			if (dp1[j]) cur++;
		}
		for (int j=ttl; j>=a[i]; j--) {
			dp1[j] = (dp1[j]+dp1[j-a[i]])%MOD;
		}
		if (cur > cnt || (cur == cnt && a[i] < val)) {
			val = a[i];
			cnt = cur;
		}
	}
	for (int i=0; i<n; i++) {
		if (a[i] == val) {
			a[i] = a[n-1];
			n--;
			break;
		}
	}
	dp2[ttl] = 1;
	for (int i=0; i<n; i++) {
		dp2 |= dp2 << a[i];
		dp2 |= dp2 >> a[i];
	}
	int o;
	for (int i=ttl; i<=2*ttl; i++) {
		if (!dp2[i]) {
			o = i;
			break;
		}
	}
	cout << val << " " << o-ttl << endl;
}