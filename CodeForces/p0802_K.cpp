#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, k;
vector< pair<int, int> > adj[100100];
long long dp[100100][2];
void dfs (int x, int p) {
	set< pair<long long, int> > cur;
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs(i.first, x);
			cur.insert(make_pair(-dp[i.first][0]-i.second, i.first));
		}
	}
	int cnt = 0;
	long long s = 0;
	int e = 0;
	set<int> inc;
	for (auto i: cur) {
		cnt++;
		s += -i.first;
		inc.insert(i.second);
		if (cnt == k) {
			e = -i.first;
			break;
		}
	}
	dp[x][0] = s-e;
	dp[x][1] = 0;
	for (auto i: adj[x]) {
		if (i.first != p) {
			if (inc.find(i.first) == inc.end()) {
				dp[x][1] = max(dp[x][1], s-e+dp[i.first][1]+i.second);
			} else {
				dp[x][1] = max(dp[x][1], s-dp[i.first][0]+dp[i.first][1]);
			}
		}
	}
}
int main () {
	cin >> n >> k;
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi >> ci;
		adj[ai].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(ai, ci));
	}
	dfs(0, 0);
	cout << max(dp[0][0], dp[0][1]) << endl;
}