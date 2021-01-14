#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int n;
int s_val[510], e_val[510];
vector<int> pts;
int s_id[510], e_id[510];
long long dp1[510][1010];
long long dp2[510][1010];
long long calc (long long a) {
	return (a*(a-1)/2)%MOD;
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s_val[i] >> e_val[i];
		pts.push_back(s_val[i]);
		pts.push_back(e_val[i]);
	}
	pts.push_back(0);
	sort(pts.begin(), pts.end());
	pts.resize(unique(pts.begin(), pts.end())-pts.begin());
	for (int i=0; i<n; i++) {
		s_id[i+1] = lower_bound(pts.begin(), pts.end(), s_val[i])-pts.begin();
		e_id[i+1] = lower_bound(pts.begin(), pts.end(), e_val[i])-pts.begin();
	}
	int m = pts.size();
	dp1[0][0] = 1;
	for (int j=1; j<m; j++) {
		dp2[0][j] = 1;
	}
	for (int i=1; i<=n; i++) {
		dp1[i][0] = 1;
		for (int j=1; j<m; j++) {
			dp1[i][j] = dp1[i-1][j];
			if (s_id[i] <= j && j <= e_id[i]) dp1[i][j] = (dp1[i][j]+dp2[i-1][j])%MOD;
			dp2[i][j] = (MOD+dp2[i-1][j]-dp2[i-1][j-1])%MOD;
			dp2[i][j] = (dp2[i][j]+dp2[i][j-1])%MOD;
			if (s_id[i] < j && j <= e_id[i]) {
				// Issue is here.
				dp2[i][j] = (dp2[i][j]+(dp2[i-1][j-1]*(pts[j]-pts[j-1]))%MOD)%MOD;
				dp2[i][j] = (dp2[i][j]+(dp1[i-1][j-1]*calc(pts[j]-pts[j-1]))%MOD)%MOD;
			}
			if (j == e_id[i]+1) dp2[i][j] = (MOD+dp2[i][j]+dp1[i][j-1]-dp1[i-1][j-1])%MOD;
		}
	}
	cout << (MOD+dp2[n][m-1]+dp1[n][m-1]-1)%MOD << endl;
}