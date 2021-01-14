#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> adj[1000000];
bool vis[1000000];
int vis_count = 0;
void dfs (int x) {
	vis[x] = true;
	vis_count++;
	for (auto i: adj[x]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}
int main () {
	int n;
	cin >> n;
	pair<int, int> ranges[n+1];
	int arr[2*n+1];
	for (int i=1; i<=n; i++) {
		cin >> ranges[i].first >> ranges[i].second;
		arr[ranges[i].first] = i;
		arr[ranges[i].second] = -i;
	}
	set< pair<int, int> > ends;
	int count = 0;
	bool pos = true;
	for (int i=1; i<=2*n; i++) {
		if (arr[i] < 0) {
			ends.erase(ends.begin());
		} else {
			ends.insert(make_pair(ranges[arr[i]].second, arr[i]));
			for (auto j: ends) {
				if (j.second == arr[i]) {
					break;
				}
				adj[arr[i]].insert(j.second);
				adj[j.second].insert(arr[i]);
				count++;
				if (count >= n) {
					pos = false;
					break;
				}
			}
		}
		if (count >= n) {
			pos = false;
			break;
		}
	}
	for (int i=1; i<=n; i++) {
		vis[i] = false;
	}
	if (count == n-1) {
		dfs(1);
		if (vis_count != n) {
			pos = false;
		}
	} else {
		pos = false;
	}
	if (pos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}