#include <iostream>
#include <iomanip>
using namespace std;
double n;
double dp[310][310][310];
void solve (int c1, int c2, int c3) {
	if (c1 == 0 && c2 == 0 && c3 == 0) return;
	if (dp[c1][c2][c3] > 0) return;
	dp[c1][c2][c3] = n;
	if (c1 > 0) {
		solve(c1-1, c2, c3);
		dp[c1][c2][c3] += c1*dp[c1-1][c2][c3];
	}
	if (c2 > 0) {
		solve(c1+1, c2-1, c3);
		dp[c1][c2][c3] += c2*dp[c1+1][c2-1][c3];
	}
	if (c3 > 0) {
		solve(c1, c2+1, c3-1);
		dp[c1][c2][c3] += c3*dp[c1][c2+1][c3-1];
	}
	dp[c1][c2][c3] /= (c1+c2+c3);
}
int main () {
	cout << fixed << setprecision(15);
	cin >> n;
	int c1 = 0, c2 = 0, c3 = 0;
	int ai;
	for (int i=0; i<n; i++) {
		cin >> ai;
		if (ai == 1) c1++;
		if (ai == 2) c2++;
		if (ai == 3) c3++;
	}
	dp[0][0][0] = 0;
	solve(c1, c2, c3);
	cout << dp[c1][c2][c3] << endl;
}