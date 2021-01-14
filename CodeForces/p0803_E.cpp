#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1005
int n, k;
string seq;
char dp[MAXN][2*MAXN];
int main () {
	cin >> n >> k;
	cin >> seq;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=2*k; j++) {
			dp[i][j] = 'X';
		}
	}
	dp[0][k] = 'D';
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=2*k; j++) {
			if ((j == 0 || j == 2*k) && i != n) continue;
			if (j > 0 && dp[i-1][j-1] != 'X' && (seq[i-1] == 'W' || seq[i-1] == '?')) dp[i][j] = 'W';
			if (dp[i-1][j] != 'X' && (seq[i-1] == 'D' || seq[i-1] == '?')) dp[i][j] = 'D';
			if (j < 2*k && dp[i-1][j+1] != 'X' && (seq[i-1] == 'L' || seq[i-1] == '?')) dp[i][j] = 'L';
		}
	}
	if (dp[n][0] == 'X' && dp[n][2*k] == 'X') {
		cout << "NO" << endl;
		return 0;
	}
	int pos = 0;
	if (dp[n][2*k] != 'X') pos = 2*k;
	string o = "";
	for (int i=n; i>0; i--) {
		o += dp[i][pos];
		if (dp[i][pos] == 'W') pos--;
		if (dp[i][pos] == 'L') pos++;
	}
	reverse(o.begin(), o.end());
	cout << o << endl;
}