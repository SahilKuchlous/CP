#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005
int n;
int days[MAXN];
int price[MAXN];
bool pos = true;
int dp[2][MAXN][2];
vector< pair<int, int> > o;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> days[i] >> price[i];
		if (days[i]-days[i-1] < abs(price[i]-price[i-1]) || (days[i]-days[i-1])%2 != abs(price[i]-price[i-1])%2) {
			pos = false;
		}
	}
	if (!pos) {
		cout << -1 << endl;
		return 0;
	}
	dp[0][0][0] = dp[1][0][0] = 1;
	for (int i=1; i<=n; i++) {
		if (days[i]-days[i-1] == price[i]-price[i-1]) {
			dp[0][i][0] = 1e9; dp[0][i][1] = -1;
			if (dp[0][i-1][0]+1 < dp[1][i-1][0]) {
				dp[1][i][0] = dp[0][i-1][0]+1; dp[1][i][1] = 0;
			} else {
				dp[1][i][0] = dp[1][i-1][0]; dp[1][i][1] = 1;
			}
			continue;
		}
		if (days[i]-days[i-1] == price[i-1]-price[i]) {
			if (dp[1][i-1][0]+1 < dp[0][i-1][0]) {
				dp[0][i][0] = dp[1][i-1][0]+1; dp[0][i][1] = 1;
			} else {
				dp[0][i][0] = dp[0][i-1][0]; dp[0][i][1] = 0;
			}
			dp[1][i][0] = 1e9; dp[1][i][1] = -1;
			continue;
		}
		if (dp[0][i-1][0]+2 < dp[1][i-1][0]+1) {
			dp[0][i][0] = dp[0][i-1][0]+2; dp[0][i][1] = 0;
		} else {
			dp[0][i][0] = dp[1][i-1][0]+1; dp[0][i][1] = 1;
		}
		if (dp[1][i-1][0]+2 < dp[0][i-1][0]+1) {
			dp[1][i][0] = dp[1][i-1][0]+2; dp[1][i][1] = 1;
		} else {
			dp[1][i][0] = dp[0][i-1][0]+1; dp[1][i][1] = 0;
		}
	}
	int dir;
	if (dp[0][n][0] < dp[1][n][0]) {
		dir = 0;
	} else {
		dir = 1;
	}
	int prv = days[n];
	for (int i=n; i>0; i--) {
		if (days[i]-days[i-1] == price[i]-price[i-1]) {
			if (dp[dir][i][1] == 1) continue;
			o.push_back(make_pair(prv-days[i-1], 1));
			prv = days[i-1];
			dir = 0;
			continue;
		}
		int dist;
		if (dir == 0) {
			dist = ((days[i]-days[i-1])+(price[i-1]-price[i]))/2;
		} else {
			dist = ((days[i]-days[i-1])+(price[i]-price[i-1]))/2;
		}
		if (days[i]-days[i-1] == price[i-1]-price[i]) {
			if (dp[dir][i][1] == 0) continue;
			o.push_back(make_pair(prv-days[i-1], 0));
			prv = days[i-1];
			dir = 1;
			continue;
		}
		if (dp[dir][i][1] == dir) {
			o.push_back(make_pair(prv-days[i]+dist, dir));
			o.push_back(make_pair(days[i]-days[i-1]-dist, dir^1));
			prv = days[i-1];
		} else {
			o.push_back(make_pair(prv-days[i]+dist, dir));
			prv = days[i]-dist;
			dir ^= 1;
		}
	}
	if (prv != 0) {
		o.push_back(make_pair(prv, dir));
	}
	reverse(o.begin(), o.end());
	cout << o.size() << '\n';
	for (auto i: o) {
		cout << i.first << " " << (i.second==0?'-':'+') << '\n';
	}
}