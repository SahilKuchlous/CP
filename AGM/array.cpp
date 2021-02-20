#include <iostream>
using namespace std;
#define MAXN 500005
#define MAXD 505
int n, k, d;
int col[MAXN];
int cost[MAXN];
long long ttl[MAXD];
long long saved[MAXD][MAXD];
long long dp[MAXD][MAXD];
int main () {
	cin >> n >> k >> d;
	for (int i=0; i<n; i++) {
		cin >> col[i];
	}
	for (int i=0; i<n; i++) {
		cin >> cost[i];
	}
	for (int i=0; i<n; i++) {
		ttl[i%k] += cost[i];
		saved[i%k][col[i]%d] += cost[i];
	}
	for (int i=0; i<k; i++) {
		for (int j=0; j<d; j++) {
			dp[i][j] = ttl[i]-saved[i][j];
		}
	}
}