#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< vector<int> > v;
int m, n, k, t;
bool pos (int min_p) {
	int dp[n+2][2];
	dp[0][0] = t;
	dp[0][1] = 0;
	int x = 0;
	for (int i=1; i<n+2; i++) {
		dp[i][0] = dp[i-1][0]-1;
		dp[i][1] = max(dp[i-1][1], i);
		int mv = 0;
		// cout << x << endl;
		while (x < k && v[x][0] == i) {
			if (v[x][1] < v[x][0]) {
				x++;
				continue;
			}
			if (v[x][2] <= min_p) {
				x++;
				continue;
			}
			if (v[x][1] <= dp[i][1]) {
				x++;
				continue;
			}
			if (v[x][1]-i > mv) {
				mv = v[x][1]-i;
			}
			x++;
		}
		dp[i][0] -= 2*(mv+1);
		dp[i][1] = max(dp[i][1], i+mv);
	}
	/*
	for (int i=0; i<n+2; i++) {
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << endl;
	*/
	if (dp[n+1][0] >= 0) {
		return true;
	} else {
		return false;
	}
}
int main () {
	cin >> m >> n >> k >> t;
	int p[m];
	for (int i=0; i<m; i++) {
		cin >> p[i];
	}
	int l, r, d;
	for (int i=0; i<k; i++) {
		cin >> l >> r >> d;
		v.push_back({l, r, d});
	}
	sort(v.begin(), v.end());
	sort(p, p+m);
	/*
	cout << endl;
	for (int i=0; i<m; i++) {
		cout << p[i] << endl;
		pos(p[i]);
	}
	cout << endl;
	*/
	int up, down, mid;
	up = m-1;
	down = 0;
	while (up > down) {
		mid = (up+down)/2;
		if (pos(p[mid])) {
			up = mid;
		} else {
			down = mid+1;
		}
	}
	cout << up << endl;
}