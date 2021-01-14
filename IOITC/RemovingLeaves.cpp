#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define MAXN 41
int n;
long long down[MAXN];
int par[MAXN];
int depth[MAXN];
map<long long, int> dp;
set<long long> vis;
queue<long long> ord;
void init () {
	for (int i=0; i<n; i++) {
		down[i] = 0;
	}
	dp.clear();
	vis.clear();
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		int pi;
		for (int i=1; i<n; i++) {
			cin >> pi;
			pi--;
			par[i] = pi;
			down[pi] |= (1ll<<i);
		}
		for (int i=1; i<n; i++) {
			depth[i] = depth[par[i]]+1;
		}
		for (int i=n-1; i>=0; i--) {
			for (int j=0; j<n; j++) {
				if (down[i] & (1ll<<j)) {
					down[i] |= down[j];
				}
			}
		}
		ord.push((1ll<<n)-1);
		while (ord.size() > 0) {
			long long cur = ord.front();
			ord.pop();
			for (int i=0; i<n; i++) {
				if (cur & (1ll<<i)) dp[cur] += depth[i];
			}
			for (int i=0; i<n; i++) {
				if ((cur & (1ll<<i)) && (cur&down[i]) == 0) {
					long long nxt = cur-(1ll<<i);
					if (vis.find(nxt) == vis.end()) {
						vis.insert(nxt);
						ord.push(nxt);
						dp[nxt] = dp[cur];
					} else {
						dp[nxt] = max(dp[nxt], dp[cur]);
					}
				}
			}
		}
		cout << dp[0] << endl;
	}
}