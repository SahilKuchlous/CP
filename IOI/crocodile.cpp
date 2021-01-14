#include "grader.h"
#include <vector>
#include <queue>
using namespace std;
int travel_plan (int n, int m, int r[][2], int l[], int k, int p[]) {
	vector< pair<int, long long> > adj[n];
	for (int i=0; i<m; i++) {
		adj[r[i][0]].push_back(make_pair(r[i][1], l[i]));
		adj[r[i][1]].push_back(make_pair(r[i][0], l[i]));
	}
	long long dist[n];
	int vis[n];
	priority_queue< pair<long long, int> > pq;
	for (int i=0; i<n; i++) {
		dist[i] = 1e15;
		vis[i] = false;
	}
	for (int i=0; i<k; i++) {
		dist[p[i]] = 0;
		vis[p[i]] = true;
		pq.push(make_pair(0, p[i]));
	}
	while (pq.size() > 0) {
		long long d = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (vis[node] == 0) {
			vis[node]++;
			continue;
		} else if (vis[node] == 1) {
			dist[node] = d;
			if (node == 0) return -dist[node];
			for (auto i: adj[node]) {
				pq.push(make_pair(dist[node]-i.second, i.first));
			}
			vis[node]++;
		}
	}
	return 0;
}