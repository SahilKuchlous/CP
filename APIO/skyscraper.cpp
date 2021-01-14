#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
int n, m;
set<int> inc[30100];
vector< pair<int, int> > adj[30100];
int dist[30100];
bool vis[30100];
priority_queue< pair<int, int> > pq;
int main () {
	cin >> n >> m;
	int bi, pi;
	int start, end;
	for (int i=0; i<m; i++) {
		cin >> bi >> pi;
		inc[bi].insert(pi);
		if (i == 0) start = bi;
		if (i == 1) end = bi;
	}
	for (int i=0; i<n; i++) {
		for (auto j: inc[i]) {
			for (int k=1; k<n; k++) {
				if (i-j*k < 0) break;
				if (inc[i-j*k].find(j) != inc[i-j*k].end()) {
					adj[i].push_back({i-j*k, k});
					break;
				}
				adj[i].push_back({i-j*k, k});
			}
			for (int k=1; k<n; k++) {
				if (i+j*k >= n) break;
				if (inc[i+j*k].find(j) != inc[i+j*k].end()) {
					adj[i].push_back({i+j*k, k});
					break;
				}
				adj[i].push_back({i+j*k, k});
			}
		}
	}
	for (int i=0; i<n; i++) {
		dist[i] = 1e9;
	} 
	dist[start] = 0;
	pq.push({0, start});
	while (pq.size() > 0) {
		pair<int, int> cur = pq.top();
		cur.first = -cur.first;
		pq.pop();
		if (cur.second == end) {
			cout << cur.first << endl;
			return 0;
		}
		if (vis[cur.second]) continue;
		vis[cur.second] = true;
		for (auto i: adj[cur.second]) {
			if (!vis[i.first] && cur.first+i.second < dist[i.first]) {
				dist[i.first] = cur.first+i.second;
				pq.push({-dist[i.first], i.first});
			}
		}
	}
	cout << -1 << endl;
}