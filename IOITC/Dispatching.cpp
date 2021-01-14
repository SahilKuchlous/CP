#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long cost[100100];
long long val[100100];
vector<int> adj[100100];
vector<long long> cur;
long long o = 0;
void dfs (int x) {
	cur.push_back(cost[x]);
	for (auto i: adj[x]) {
		dfs(i);
	}
}
int main () {
	cin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi >> ci;
		cost[i] = bi;
		val[i] = ci;
		if (ai == 0) continue;
		adj[ai-1].push_back(i);
	}
	for (int i=0; i<n; i++) {
		cur.clear();
		dfs(i);
		sort(cur.begin(), cur.end());
		long long cnt = 0, sum = 0;
		for (int j=0; j<cur.size(); j++) {
			if (sum + cur[j] <= m) {
				sum += cur[j];
				cnt++;
			}
		}
		o = max(o, val[i]*cnt);
	}
	cout << o << endl;
}