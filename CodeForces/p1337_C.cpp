#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[200100];
pair<int, int> stats[200100];
long long o = 0;
bool sort_func (const pair<int, int> p1, const pair<int, int> p2) {
	return p1.first-p1.second > p2.first-p2.second;
}
void dfs (int x, int p, int d) {
	stats[x].first = d;
	stats[x].second = 1;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x, d+1);
			stats[x].second += stats[i].second;
		}
	}
}
int main () {
	int n, k;
	cin >> n >> k;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0, 1);
	sort(stats, stats+n, sort_func);
	for (int i=0; i<k; i++) {
		o += stats[i].first;
		o -= stats[i].second;
	}
	cout << o << endl;
}