#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> down[5000];
long long val;
long long best = 1e16;
int depth[5000];
int cnt;
void reset () {
	val = cnt = 0;
	for (int i=0; i<n; i++) {
		depth[i] = -1;
	}
}
void bfs (int x) {
	queue<int> q;
	q.push(x);
	depth[x] = 1;
	while (q.size() > 0) {
		cnt++;
		int cur = q.front();
		q.pop();
		val += depth[cur];
		for (auto i: down[cur]) {
			if (depth[i] > -1) continue;
			depth[i] = depth[cur]+1;
			q.push(i);
		}
	}
	if (cnt < n) val = 1e16;
}
int main () {
	cin >> n;
	int ci, ai;
	for (int i=0; i<n; i++) {
		cin >> ci;
		for (int j=0; j<ci; j++) {
			cin >> ai;
			ai--;
			down[ai].push_back(i);
		}
	}
	for (int i=0; i<n; i++) {
		reset();
		bfs(i);
		best = min(best, val);
	}
	cout << best << endl;
}