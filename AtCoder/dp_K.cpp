#include <iostream>
using namespace std;
int n, k;
int a[110];
bool vis[100100][2];
bool dp[100100][2];
bool check (int x, int p) {
	if (x < 0) return true;
	if (vis[x][p]) return dp[x][p];
	vis[x][p] = true;
	for (int i=0; i<n; i++) {
		if (!check(x-a[i], !p)) dp[x][p] = true;
	}
	return dp[x][p];
}
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (check(k, 0)) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}