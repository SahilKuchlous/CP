#include <iostream>
#include <vector>
using namespace std;
int n, m;
int c1, c2, c3;
vector<int> adj[5001];
int color[5001];
vector<int> grps;
int cnt = 1;
bool pos = true;
int dp[5001][10001];
bool sign[5001][10001];
void dfs (int x, int c) {
	color[x] = c*cnt;
	grps[cnt-1] += c;
	for (auto i: adj[x]) {
		if (color[i] == 0) {
			dfs(i, -c);
		} else if (color[i] != -c*cnt) {
			pos = false;
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> c1 >> c2 >> c3;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		if (color[i] == 0) {
			grps.push_back(0);
			dfs(i, 1);
			cnt++;
		}
	}
	if (!pos) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i=0; i<cnt; i++) {
		for (int j=-5000; j<=5000; j++) {
			dp[i][j+5000] = 1e8;
		}
	}
	dp[0][5000] = 0;
	for (int i=1; i<cnt; i++) {
		for (int j=-5000; j<=5000; j++) {
			if (dp[i-1][j+5000] != 1e8 && j+grps[i-1] <= 5000 && j+grps[i-1] >= -5000) {
				dp[i][j+grps[i-1]+5000] = j;
				sign[i][j+grps[i-1]+5000] = true;
			}
			if (dp[i-1][j+5000] != 1e8 && j-grps[i-1] <= 5000 && j-grps[i-1] >= -5000) {
				dp[i][j-grps[i-1]+5000] = j;
				sign[i][j-grps[i-1]+5000] = false;
			}
		}
	}
	if (dp[cnt-1][c1+c3-c2+5000] == 1e8) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int cur = c1+c3-c2;
	for (int i=cnt-1; i>0; i--) {
		for (int j=0; j<n; j++) {
			if (abs(color[j]) == i && !sign[i][cur+5000]) color[j] = -color[j];
		}
		cur = dp[i][cur+5000];
	}
	for (int i=0; i<n; i++) {
		if (color[i] > 0) {
			if (c1 > 0) {
				cout << 1;
				c1--;
			} else {
				cout << 3;
				c3--;
			}
		} else {
			cout << 2;
			c2--;
		}
	}
	cout << endl;
	return 0;
}