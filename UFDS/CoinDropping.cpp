#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n;
vector<int> adj[MAXN];
pair<int, int> o1[MAXN], o2[MAXN];
void dfs1 (int x, int p) {
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
	}
	if (o1[x].first != p) {
		if (o1[o1[x].first].first != x) {
			o1[x].second = o1[o1[x].first].second;
		} else {
			o1[x].second = o2[o1[x].first].second;
		}
	}
	if (o2[x].first != p && o2[x].first != x) {
		if (o1[o2[x].first].first != x) {
			o2[x].second = o1[o2[x].first].second;
		} else {
			o2[x].second = o2[o2[x].first].second;
		}
	}
}
void dfs2 (int x, int p) {
	if (o1[x].first == p) {
		if (o1[o1[x].first].first != x) {
			o1[x].second = o1[o1[x].first].second;
		} else {
			o1[x].second = o2[o1[x].first].second;
		}
	}
	if (o2[x].first == p && o2[x].first != x) {
		if (o1[o2[x].first].first != x) {
			o2[x].second = o1[o2[x].first].second;
		} else {
			o2[x].second = o2[o2[x].first].second;
		}
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x);
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		o1[i].first = o2[i].first = 1e8;
		for (auto j: adj[i]) {
			if (j < o1[i].first) {
				o2[i].first = o1[i].first;
				o1[i].first = j;
			} else if (j < o2[i].first) {
				o2[i].first = j;
			}
		}
		if (o2[i].first == 1e8) {
			o2[i].first = o2[i].second = i;
		}
	}
	dfs1(0, 0);
	dfs2(0, 0);
	for (int i=0; i<n; i++) {
		cout << o1[i].second+1 << '\n';
	}
}