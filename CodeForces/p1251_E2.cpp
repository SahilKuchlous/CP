#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> grps[200100];
multiset<int> opts;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			grps[i].clear();
		}
		opts.clear();
		int req[n], cost[n];
		for (int i=0; i<n; i++) {
			cin >> req[i] >> cost[i];
			grps[req[i]].push_back(i);
		}
		int cnt = n;
		long long ans = 0;
		for (int i=n-1; i>=0; i--) {
			cnt -= grps[i].size();
			for (auto j: grps[i]) {
				opts.insert(cost[j]);
			}
			for (int j=cnt; j<i; j++) {
				ans += *opts.begin();
				opts.erase(opts.begin());
			}
			cnt = max(cnt, i);
		}
		cout << ans << endl;
	}
}
