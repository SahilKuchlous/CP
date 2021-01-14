#include <iostream>
#include <string>
using namespace std;
string cur;
long long dp[20][11][11][2][2];
void reset () {
	for (int i=0; i<20; i++) {
		for (int j=0; j<11; j++) {
			for (int k=0; k<11; k++) {
				dp[i][j][k][0][0] = dp[i][j][k][0][1] = -1;
				dp[i][j][k][1][0] = dp[i][j][k][1][1] = -1;
			}
		}
	}
}
long long calc (int pos, int prev1, int prev2, bool top, bool f) {
	if (pos == cur.size()) return 1;
	if (dp[pos][prev1][prev2][top][f] > -1) return dp[pos][prev1][prev2][top][f];
	dp[pos][prev1][prev2][top][f] = 0;
	if (f) dp[pos][prev1][prev2][top][f] += calc(pos+1, prev1, prev2, false, true);
	if (top) {
		for (int i=0; i<cur.at(pos)-'0'; i++) {
			if (i == 0 && f) continue;
			if (i != prev1 && i != prev2) dp[pos][prev1][prev2][top][f] += calc(pos+1, i, prev1, false, false);
		}
		if (cur.at(pos)-'0' != prev1 && cur.at(pos)-'0' != prev2 && !(cur.at(pos) == '0' && f)) dp[pos][prev1][prev2][top][f] += calc(pos+1, cur.at(pos)-'0', prev1, true, false);
	} else {
		for (int i=0; i<10; i++) {
			if (i == 0 && f) continue;
			if (i != prev1 && i != prev2) dp[pos][prev1][prev2][top][f] += calc(pos+1, i, prev1, top, false);
		}
	}
	return dp[pos][prev1][prev2][top][f];
}
int main () {
	long long a, b;
	cin >> a >> b;
	cur = to_string(a-1);
	reset();
	long long c1 = (a == 0 ? 0 : calc(0, 10, 10, true, true));
	cur = to_string(b);
	reset();
	long long c2 = calc(0, 10, 10, true, true);
	cout << c2-c1 << endl;
}