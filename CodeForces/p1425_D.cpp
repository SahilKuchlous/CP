#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
using namespace std;
#define MAXN 2005
#define MOD 1000000007
int n, m, r;
pair<int, int> pos[MAXN];
long long danger[MAXN];
long long nck[MAXN][MAXN];
long long psum[MAXN][MAXN];
vector<int> adj[MAXN];
long long shared[MAXN][MAXN];
long long o = 0;
int main () {
	cin >> n >> m >> r;
	for (int i=0; i<n; i++) {
		cin >> pos[i].first >> pos[i].second >> danger[i];
		psum[pos[i].first][pos[i].second]++;
	}
	for (int i=0; i<MAXN; i++) {
		for (int j=0; j<MAXN; j++) {
			if (i > 0) psum[i][j] += psum[i-1][j];
			if (j > 0) psum[i][j] += psum[i][j-1];
			if (i > 0 && j > 0) psum[i][j] -= psum[i-1][j-1];
		}
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			if (i < j) continue;
			if (i == 0 || j == 0) {
				nck[i][j] = 1;
				continue;
			}
			nck[i][j] = (nck[i-1][j-1]+nck[i-1][j])%MOD;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (abs(pos[i].first-pos[j].first) <= r && abs(pos[i].second-pos[j].second) <= r) adj[i].push_back(j);
			int x1, y1, x2, y2;
			x1 = max(0, max(pos[i].first, pos[j].first)-r-1);
			y1 = max(0, max(pos[i].second, pos[j].second)-r-1);
			x2 = min(MAXN-1, min(pos[i].first, pos[j].first)+r);
			y2 = min(MAXN-1, min(pos[i].second, pos[j].second)+r);
			if (x1 > x2 || y1 > y2) continue;
			shared[i][j] = psum[x2][y2]-psum[x1][y2]-psum[x2][y1]+psum[x1][y1];
		}
	}
	for (int i=0; i<n; i++) {
		int cnt = (nck[n][m]-nck[n-adj[i].size()][m]+MOD)%MOD;
		o = (o + danger[i]*danger[i]%MOD*cnt%MOD) % MOD;
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			long long val = (nck[n][m]-nck[n-shared[i][j]][m]+MOD)%MOD;
			val = (val+nck[n-shared[i][j]][m])%MOD;
			val = (val-nck[n-adj[i].size()][m]-nck[n-adj[j].size()][m]+MOD+MOD)%MOD;
			val = (val+nck[n-adj[i].size()-adj[j].size()+shared[i][j]][m])%MOD;
			o = (o + 2*danger[i]*danger[j]%MOD*val%MOD) % MOD;
		}
	}
	cout << o << endl;
}