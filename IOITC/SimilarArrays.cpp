#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 2005
int n;
int a[MAXN], b[MAXN];
double hi, lo;
vector<double> ord;
vector<double> values[MAXN];
vector<double> dp[MAXN];
void reset () {
	ord.clear();
	lo = 1e18;
	hi = 0;
	for (int i=0; i<n; i++) {
		dp[i].clear();
		values[i].clear();
	}
}
double cost (double r, int x, int y) {
	double ans = 0;
	for (int i=x; i<=y; i++) {
		ans += (a[i]-r*b[i])*(a[i]-r*b[i]);
	}
	return ans;
}
double search (int x, int y) {
	double l = lo, r = hi, m;
	while (abs(r-l) > 1e-10) {
		m = (r+l)/2;
		double p1 = (m+l)/2, p2 = (r+m)/2;
		if (cost(p1, x, y) > cost(p2, x, y)) {
			l = p1;
		} else {
			r = p2;
		}
	}
	return l;
}
void solve () {
	cin >> n;
	reset();
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		double best = 1.0*a[i]/b[i];
		hi = max(hi, best);
		lo = min(lo, best);
	}
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			double val = search(i, j);
			for (int k=i; k<=j; k++) {
				values[k].push_back(val);
			}
		}
	}
	for (int i=0; i<n; i++) {
		sort(values[i].begin(), values[i].end());
	}
	for (int i=0; i<n; i++) {
		dp[n].push_back(0);
	}
	for (int i=n-1; i>=0; i--) {
		dp[i].push_back(1e18);
		for (int j=1; j<=values[i].size(); j++) {
			double cur = (a[i]-values[i][j-1]*b[i])*(a[i]-values[i][j-1]*b[i]);
			int ind = upper_bound(values[i+1].begin(), values[i+1].end(), values[i][j-1])-values[i+1].begin();
			// cout << ind << endl;
			dp[i].push_back(min(dp[i][j-1], dp[i+1][ind]+cur));
			// cout << i << " " << j << " " << dp[i][j] << endl;
		}
		dp[i].push_back(dp[i][values[i].size()]);
	}
	cout << dp[0][values[0].size()] << '\n';
}
/*
void solve () {
	cin >> n;
	reset();
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		double best = 1.0*a[i]/b[i];
		hi = max(hi, best);
		lo = min(lo, best);
	}
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			ord.push_back(search(i, j));
		}
	}
	sort(ord.begin(), ord.end());
	for (int i=0; i<n; i++) {
		dp[n][i] = 0;
	}
	for (int i=n-1; i>=0; i--) {
		dp[i][0] = 1e18;
		for (int j=1; j<=ord.size(); j++) {
			double cur = (a[i]-ord[j-1]*b[i])*(a[i]-ord[j-1]*b[i]);
			dp[i][j] = min(dp[i][j-1], dp[i+1][j]+cur);
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[0][ord.size()] << endl;
}
*/
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}