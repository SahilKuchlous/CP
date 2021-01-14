#include <iostream>
using namespace std;
int n, p;
int str[100100];
int freq[17];
bool adj[17][17];
bool vis[17][17][1<<17];
bool pos[1<<17];
void mark (int a, int b, int mask) {
	if (vis[a][b][mask]) return;
	vis[a][b][mask] = true;
	pos[mask] = false;
	for (int i=0; i<p; i++) {
		if (i == a || i == b) continue;
		if (mask & (1<<i)) {
			mark(a, b, mask-(1<<i));
		}
	}
}
bool dp[1<<17];
int best = 1e6;
int main () {
	cin >> n >> p;
	char ci;
	for (int i=0; i<n; i++) {
		cin >> ci;
		str[i] = ci-'a';
		freq[str[i]]++;
	}
	for (int i=0; i<p; i++) {
		for (int j=0; j<p; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i=0; i<(1<<p); i++) {
		pos[i] = true;
	}
	for (int i=0; i<p; i++) {
		for (int j=0; j<p; j++) {
			if (adj[i][j]) continue;
			int prev = -1;
			int mask = 0;
			for (int x=0; x<n; x++) {
				if (str[x] != i && str[x] != j) mask |= (1<<str[x]);
				if (str[x] == j && prev > -1) {
					mark(i, j, (((1<<p)-1)^mask));
				}
				if (str[x] == i) {
					prev = x;
					mask = 0;
				}
			}
		}
	}
	dp[(1<<p)-1] = true;
	for (int i=(1<<p)-1; i>=0; i--) {
		if (!dp[i]) continue;
		int cur = 0;
		for (int j=0; j<p; j++) {
			if (i & (1<<j)) {
				cur += freq[j];
				if (pos[i-(1<<j)]) dp[i-(1<<j)] = true;
			}
		}
		best = min(best, cur);
	}
	cout << best << endl;
}