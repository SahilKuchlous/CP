#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> adj[1000000];
bool vis[1000000];
int o = 0;
void bfs (int x) {
	queue<int> q;
	q.push(x);
	while (q.size()) {
		int cur = q.front();
		vis[cur] = true;
		for (int i: adj[cur]) {
			if (!vis[i]) q.push(i); 
		}
		q.pop();
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai;
	for (int i=0; i<n; i++) {
		cin >> ai;
		ai--;
		adj[i].push_back(ai);
		adj[ai].push_back(i);
	}
	for (int i=0; i<n; i++) {
		if (!vis[i]) {
			bfs(i);
			o++;
		}
	}
	cout << o << endl;
}