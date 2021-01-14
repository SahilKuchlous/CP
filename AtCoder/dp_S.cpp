#include <iostream>
using namespace std;
#define MOD 1000000007
string s;
int d;
long long dp[10001][101][2];
bool vis[10001][101][2];
long long solve (int pos, int val, bool top) {
	if (pos == s.length()) return val == 0;
	if (vis[pos][val][top]) return dp[pos][val][top];
	vis[pos][val][top] = true;
	if (top) {
		for (int i=0; i<s[pos]-'0'; i++) {
			dp[pos][val][top] += solve(pos+1, (val+i)%d, false);
			dp[pos][val][top] %= MOD;
		}
		dp[pos][val][top] += solve(pos+1, (val+(s[pos]-'0'))%d, true);
		dp[pos][val][top] %= MOD;
		return dp[pos][val][top];
	}
	for (int i=0; i<10; i++) {
		dp[pos][val][top] += solve(pos+1, (val+i)%d, false);
		dp[pos][val][top] %= MOD;
	}
	return dp[pos][val][top];
}
int main () {
	cin >> s >> d;
	cout << (MOD+solve(0, 0, true)-1)%MOD << endl;
}