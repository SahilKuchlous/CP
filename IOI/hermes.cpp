#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<int, int> points[n+1];
	for (int i=1; i<=n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	points[0] = make_pair(0, 0);
	long long dp1[2100], dp2[2100];
	for (int i=-1000; i<=1000; i++) {
		dp1[i+1000] = dp2[i+1000] = abs(i);
	}
	long long np1[2100], np2[2100];
	for (int i=1; i<=n; i++) {
		for (int j=-1000; j<=1000; j++) {
			np1[j+1000] = min(dp1[j+1000]+abs(points[i].first-points[i-1].first), dp2[points[i].first+1000]+abs(j-points[i-1].second));
			np2[j+1000] = min(dp1[points[i].second+1000]+abs(j-points[i-1].first), dp2[j+1000]+abs(points[i].second-points[i-1].second));
		}
		for (int j=-1000; j<=1000; j++) {
			dp1[j+1000] = np1[j+1000];
			dp2[j+1000] = np2[j+1000];
		}
	}
	long long o = dp1[0];
	for (int j=-1000; j<=1000; j++) {
		o = min(o, dp1[j+1000]);
		o = min(o, dp2[j+1000]);
	}
	cout << o << endl;
}