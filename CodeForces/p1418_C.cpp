#include <iostream>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN];
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<=n; i++) {
			dp1[i] = dp2[i] = MAXN;
		}
		dp2[0] = 0;
		for (int i=1; i<=n; i++) {
			int cost = a[i];
			dp1[i] = min(dp1[i], dp2[i-1]+cost);
			dp2[i] = min(dp2[i], dp1[i-1]);
			if (i > 1) {
				cost += a[i-1];
				dp1[i] = min(dp1[i], dp2[i-2]+cost);
				dp2[i] = min(dp2[i], dp1[i-2]);
			}
		}
		cout << min(dp1[n], dp2[n]) << endl;
	}
}