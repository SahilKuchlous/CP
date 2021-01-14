#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("yinyang.in");
ofstream fout("yinyang.out");
int n;
set< pair<int, int> > adj[100100];
int subtree[100100];
pair<int, int> paths_main[200100];
pair<int, int> paths_sub[200100];
int off_main, off_sub;
int mid = 100000;
long long ans = 0;
void calc_subtree (int x, int p) {
	subtree[x] = 1;
	for (auto i: adj[x]) {
		if (i.first != p) {
			calc_subtree(i.first, x);
			subtree[x] += subtree[i.first];
		}
	}
}
void find_paths (int x, int p, int cur, int minv, int maxv) {
	if (cur == minv || cur == maxv) {
		minv = min(minv, cur-1);
		maxv = max(maxv, cur+1);
		paths_sub[off_sub+cur].second++;
	} else {
		paths_sub[off_sub+cur].first++;
	}
	for (auto i: adj[x]) {
		if (i.first != p) {
			find_paths(i.first, x, cur+i.second, minv, maxv);
		}
	}
}
void solve (int x) {
	calc_subtree(x, -1);
	int root = x, p = -1, size = subtree[x];
	bool centroid;
	while (true) {
		centroid = true;
		for (auto i: adj[root]) {
			if (i.first != p && subtree[i.first] > size/2) {
				centroid = false;
				p = root;
				root = i.first;
				break;
			}
		}
		if (centroid) break;
	}
	calc_subtree(root, -1);
	off_main = size;
	for (int i=0; i<=2*off_main+1; i++) {
		paths_main[i] = make_pair(0, 0);
	}
	paths_main[off_main].second = 1;
	for (auto i: adj[root]) {
		off_sub = subtree[i.first];
		for (int j=0; j<=2*off_sub+1; j++) {
			paths_sub[j] = make_pair(0, 0);
		}
		find_paths(i.first, root, i.second, i.second, i.second);
		for (int j=-off_sub; j<=off_sub; j++) {
			ans += paths_sub[off_sub+j].first*paths_main[off_main-j].first;
			ans += paths_sub[off_sub+j].second*paths_main[off_main-j].first;
			ans += paths_sub[off_sub+j].first*paths_main[off_main-j].second;
		}
		ans += paths_sub[off_sub].second*(paths_main[off_main].second-1);
		for (int j=-off_sub; j<=off_sub; j++) {
			paths_main[off_main+j].first += paths_sub[off_sub+j].first;
			paths_main[off_main+j].second += paths_sub[off_sub+j].second;
		}
	}
	for (auto i: adj[root]) {
		adj[i.first].erase(make_pair(root, i.second));
	}
	for (auto i: adj[root]) {
		solve(i.first);
	}
}
int main () {
	fin >> n;
	int ai, bi, ci;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi >> ci;
		ai--;
		bi--;
		if (ci == 0) ci = -1;
		adj[ai].insert(make_pair(bi, ci));
		adj[bi].insert(make_pair(ai, ci));
	}
	solve(0);
	fout << ans << endl;
}