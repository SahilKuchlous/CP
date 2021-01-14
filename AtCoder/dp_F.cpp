#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int dp[3100][3100];
pair<int, int> back[3100][3100];
bool inc[3100][3100];
int main () {
	cin >> a >> b;
	for (int i=1; i<=a.size(); i++) {
		for (int j=1; j<=b.size(); j++) {
			if (dp[i-1][j] > dp[i][j]) {
				dp[i][j] = dp[i-1][j];
				back[i][j] = {i-1, j};
			}
			if (dp[i][j-1] > dp[i][j]) {
				dp[i][j] = dp[i][j-1];
				back[i][j] = {i, j-1};
			}
			if (a[i-1] == b[j-1] && dp[i-1][j-1]+1 > dp[i][j]) {
				dp[i][j] = dp[i-1][j-1]+1;
				back[i][j] = {i-1, j-1};
				inc[i][j] = true;
			}
		}
	}
	pair<int, int> cur = {a.size(), b.size()};
	string o = "";
	while (cur != make_pair(0, 0)) {
		if (inc[cur.first][cur.second]) o += a[cur.first-1];
		cur = back[cur.first][cur.second];
	}
	reverse(o.begin(), o.end());
	cout << o << endl;
}