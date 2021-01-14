#include <iostream>
using namespace std;
#define MOD 1000000007
int n, t;
pair<int, int> songs[15];
long long dp[(1<<15)][3];
long long o = 0;
int main () {
	cin >> n >> t;
	for (int i=0; i<n; i++) {
		cin >> songs[i].first >> songs[i].second;
		songs[i].second--;
	}
	for (int i=1; i<(1<<n); i++) {
		int cnt = 0, bit, ttl = 0;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				bit = j;
				cnt++;
				ttl += songs[j].first;
			}
		}
		if (cnt == 1) {
			dp[i][songs[bit].second] = 1;
			if (ttl == t) o = (o+1)%MOD;
			continue;
		}
		for (int j=0; j<n; j++) {
			if ((i&(1<<j)) == 0) continue;
			if (songs[j].second != 0) dp[i][songs[j].second] = (dp[i][songs[j].second]+dp[i-(1<<j)][0])%MOD;
			if (songs[j].second != 1) dp[i][songs[j].second] = (dp[i][songs[j].second]+dp[i-(1<<j)][1])%MOD;
			if (songs[j].second != 2) dp[i][songs[j].second] = (dp[i][songs[j].second]+dp[i-(1<<j)][2])%MOD;
		}
		if (ttl == t) o = (o+dp[i][0]+dp[i][1]+dp[i][2])%MOD;
	}
	cout << o << endl;
}