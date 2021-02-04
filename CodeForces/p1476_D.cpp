#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	n++;
	string dir;
	cin >> dir;
	int dp1[n];
	dp1[0] = 1;
	for (int i=1; i<n; i++) {
		dp1[i] = 1;
		if (dir[i-1] == 'R') continue;
		dp1[i]++;
		if (i == 1 || dir[i-2] == 'L') continue;
		dp1[i] += dp1[i-2];
	}
	int dp2[n];
	dp2[n-1] = 1;
	for (int i=n-2; i>=0; i--) {
		dp2[i] = 1;
		if (dir[i] == 'L') continue;
		dp2[i]++;
		if (i == n-2 || dir[i+1] == 'R') continue;
		dp2[i] += dp2[i+2];
	}
	for (int i=0; i<n; i++) {
		cout << dp1[i]+dp2[i]-1 << " ";
	}
	cout << endl;
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