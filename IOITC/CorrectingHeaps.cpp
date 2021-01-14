#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int h;
int val[2000000], cost[2000000];
int b;
vector< pair<int, int> > opts[2000000];
pair<int, int> cur;
void dfs (int x) {
	if (2ll*x >= (1<<h)) {
		opts[x].push_back(make_pair(-val[x], 0));
		opts[x].push_back(make_pair(100, cost[x]));
		return;
	}
	dfs(2*x);
	dfs(2*x+1);
	int p1 = 0, p2 = 0;
	int c1 = opts[2*x][0].second, c2 = opts[2*x+1][0].second;
	bool done = false;
	while (p1 < opts[2*x].size() || p2 < opts[2*x+1].size()) {
		if (!done && ((b == 0 && val[x] >= -opts[2*x][p1].first && val[x] >= -opts[2*x+1][p2].first) || (b == 1 && val[x] > -opts[2*x][p1].first && val[x] > -opts[2*x+1][p2].first))) {
			cur = make_pair(-val[x], c1+c2);
			done = true;
		} else if (-opts[2*x][p1].first > -opts[2*x+1][p2].first) {
			cur = make_pair(opts[2*x][p1].first-(b==1?1:0), c1 + c2 + cost[x]);
			p1++;
			c1 = max(c1, opts[2*x][p1].second);
		} else if (-opts[2*x+1][p2].first > -opts[2*x][p1].first) {
			cur = make_pair(opts[2*x+1][p2].first-(b==1?1:0), c1 + c2 + cost[x]);
			p2++;
			c2 = max(c2, opts[2*x+1][p2].second);
		} else {
			cur = make_pair(opts[2*x][p1].first-(b==1?1:0), c1 + c2 + cost[x]);
			p1++; p2++;
			c1 = max(c1, opts[2*x][p1].second); c2 = max(c2, opts[2*x+1][p2].second);
		}
		while (opts[x].size() > 0 && cur.second <= opts[x].back().second) {
			opts[x].pop_back();
		}
		opts[x].push_back(cur);
	}
}
int main () {
	cin >> h;
	for (int i=1; i<(1<<h); i++) {
		cin >> val[i];
	}
	for (int i=1; i<(1<<h); i++) {
		cin >> cost[i];
	}
	cin >> b;
	dfs(1);
	cout << opts[1][0].second << endl;
}