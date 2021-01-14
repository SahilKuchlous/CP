#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	long long wts[m];
	set< pair<int, int> > adj[n];
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--;
		bi--;
		adj[ai].insert(make_pair(bi, i));
		adj[bi].insert(make_pair(ai, i));
		wts[i] = ci;
	}
	vector<int> o;
	long long dist[n];
	for (int i=0; i<n; i++) dist[i] = 1e16;
	bool vis[n];
	for (int i=0; i<n; i++) vis[i] = false;
	set< pair<long long, int> > cur;
	cur.insert(make_pair(0, 0));
	dist[0] = 0;
	int edge[n];
	for (int i=0; i<n; i++) edge[i] = -1;
	int c = 0;
	int node;
	for (int i=0; i<=k; i++) {
		if (cur.size() == 0) break;
		c++;
		node = (*cur.begin()).second;
		vis[node] = true;
		cur.erase(cur.begin());
		if (edge[node] != -1) o.push_back(edge[node]+1);
		for (auto i: adj[node]) {
			if (!vis[i.first] && dist[node]+wts[i.second] < dist[i.first]) {
				cur.erase(make_pair(dist[i.first], i.first));
				dist[i.first] = dist[node]+wts[i.second];
				cur.insert(make_pair(dist[i.first], i.first));
				edge[i.first] = i.second;
			}
		}
	}
	cout << c-1 << endl;
	for (auto i: o) cout << i << " ";
	cout << endl;
}