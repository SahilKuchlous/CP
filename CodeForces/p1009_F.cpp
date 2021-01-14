#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int n;
vector<int> adj[1000100];
map<int, int> cnt[1000100];
set< pair<int, int> > ord[1000100];
int ptr[1000100];
int o[1000100];
void dfs (int x, int p, int d) {
	cnt[x][d] = 1;
	ord[x].insert(make_pair(-1, d));
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x, d+1);
		if (cnt[ptr[i]].size() > cnt[ptr[x]].size()) swap(ptr[x], ptr[i]);
		for (auto j: cnt[ptr[i]]) {
			ord[ptr[x]].erase(make_pair(-cnt[ptr[x]][j.first], j.first));
			cnt[ptr[x]][j.first] += j.second;
			ord[ptr[x]].insert(make_pair(-cnt[ptr[x]][j.first], j.first));
		}
	}
	o[x] = ord[ptr[x]].begin()->second-d;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		ptr[i] = i;
	}
	dfs(0, 0, 0);
	for (int i=0; i<n; i++) {
		cout << o[i] << '\n';
	}
}