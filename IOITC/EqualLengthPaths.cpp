#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 200005
int n, m;
vector< pair<int, int> > adj[MAXN];
queue<int> ord;
bool vis[MAXN];
bool done[MAXN];
pair<int, int> o[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, i));
		adj[bi].push_back(make_pair(ai, i));
	}
	ord.push(0);
	done[0] = vis[0] = true;
	while (ord.size() > 0) {
		int cur = ord.front();
		ord.pop();
		done[cur] = true;
		for (auto i: adj[cur]) {
			if (done[i.first]) continue;
			if (!vis[i.first]) ord.push(i.first);
			o[i.second] = make_pair(i.first+1, cur+1);
			vis[i.first] = true;
		}
	}
	for (int i=0; i<m; i++) {
		cout << o[i].first << " " << o[i].second << '\n';
	}
}