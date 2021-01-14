#include <iostream>
using namespace std;
pair<long long, long long> mon[300000];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> mon[i].first >> mon[i].second;
		}
		long long cost = mon[n-1].first;
		long long ttl, minb;
		ttl = minb = min(mon[0].first, mon[n-1].second);
		for (int i=0; i<n-1; i++) {
			cost += mon[i].first;
			ttl += min(mon[i+1].first, mon[i].second);
			minb = min(minb, min(mon[i+1].first, mon[i].second));
		}
		cout << cost-ttl+minb << endl;
	}
}