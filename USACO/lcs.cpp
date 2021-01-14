#include <iostream>
#include <string>
using namespace std;
int main () {
	string a, b;
	cin >> a >> b;
	int dp[a.length()+1][b.length()+1];
	for (int i=0; i<=a.length(); i++) {
		dp[i][0] = 0;
	}
	for (int i=0; i<=b.length(); i++) {
		dp[0][i] = 0;
	}
	for (int i=1; i<=a.length(); i++) {
		for (int j=1; j<=b.length(); j++) {
			dp[i][j] = max(dp[i-1][j], dp[j][i-1]);
			if (a.at(i-1) == b.at(j-1)) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		}
	}
	cout << dp[a.length()][b.length()] << endl;
}