#include <iostream>
#include <vector>
using namespace std;
int k, n, m, o;
long long dp[50010][5][5][20];
void init () {
	for (int i1=0; i1<n; i1++) {
		for (int i2=0; i2<k; i2++) {
			for (int i3=0; i3<k; i3++) {
				for (int i4=0; i4<20; i4++) {
					dp[i1][i2][i3][i4] = 1e9;
				}
			}
		}
	}
}
void process () {
	for (int dist=1; dist<20; dist++) {
		for (int i=0; i<(n/k)+1; i++) {
			if (i+(1<<dist) >= n) continue;
			for (int s=0; s<k; s++) {
				for (int e=0; e<k; e++) {
					for (int m=0; m<k; m++) {
						dp[i][s][e][dist] = min(dp[i][s][e][dist], dp[i][s][m][dist-1]+dp[i+(1<<(dist-1))][m][e][dist-1]);
					}
				}
			}
		}
	}
}
long long calc (int a, int b) {
	int pos = a/k;
	long long cur[5], temp[5];
	for (int i=0; i<5; i++) cur[i] = temp[i] = 1e9;
	cur[a%k] = 0;
	for (int i=19; i>=0; i--) {
		if (pos+(1<<i) > b/k) continue;
		for (int m=0; m<k; m++) {
			for (int e=0; e<k; e++) {
				temp[e] = min(temp[e], cur[m]+dp[pos][m][e][i]);
			}
		}
		for (int s=0; s<k; s++) {
			cur[s] = temp[s];
			temp[s] = 1e9;
		}
		pos += 1<<i;
	}
	return (cur[b%k]==1e9 ? -1:cur[b%k]);
}
int main () {
	cin >> k >> n >> m >> o;
	init();
	int ai, bi, wi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> wi;
		dp[ai/k][ai%k][bi%k][0] = wi;
	}
	process();
	for (int i=0; i<o; i++) {
		cin >> ai >> bi;
		cout << calc(ai, bi) << endl;
	}
}