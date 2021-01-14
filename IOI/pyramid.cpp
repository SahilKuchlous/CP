#include <iostream>
#include <set>
using namespace std;
int m, n, sy1, sx1, sy2, sx2;
int grid[1000][1000];
int presum[1000][1000];
set< pair<int, pair<int, int> > > cols[1000];
set< pair<int, pair<int, int> > > cur;
int calc (int x, int y, int a, int b) {
	a--; b--;
	int o = presum[x+a][y+b];
	if (x > 0) o -= presum[x-1][y+b];
	if (y > 0) o -= presum[x+a][y-1];
	if (x > 0 && y > 0) o += presum[x-1][y-1];
	return o;
}
int main () {
	cin >> m >> n >> sy1 >> sx1 >> sy2 >> sx2;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			presum[i][j] = grid[i][j];
			if (i > 0) presum[i][j] += presum[i-1][j];
			if (j > 0) presum[i][j] += presum[i][j-1];
			if (i > 0 && j > 0) presum[i][j] -= presum[i-1][j-1];
		}
	}
	for (int i=0; i<sx1-sx2-1; i++) {
		for (int j=0; j<m-sy2; j++) {
			cols[j].insert({calc(i, j, sx2, sy2), {i, j}});
		}
	}
	int score;
	int best = 0;
	pair<int, int> ans1, ans2;
	for (int i=0; i<=n-sx1; i++) {
		for (int j=0; j<m-sy2; j++) {
			cols[j].erase({calc(i, j, sx2, sy2), {i, j}});
			cols[j].insert({calc(i+sx1-sx2-1, j, sx2, sy2), {i+sx1-sx2-1, j}});
		}
		cur.clear();
		for (int j=0; j<sy1-sy2-1; j++) {
			cur.insert(*cols[j].begin());
		}
		for (int j=0; j<=m-sy1; j++) {
			cur.erase(*cols[j].begin());
			cur.insert(*cols[j+sy1-sy2-1].begin());
			score = calc(i, j, sx1, sy1);
			score -= cur.begin()->first;
			if (score > best) {
				best = score;
				ans1 = {i, j};
				ans2 = cur.begin()->second;
			}
		}
	}
	cout << ans1.second+1 << " " << ans1.first+1 << endl;
	cout << ans2.second+1 << " " << ans2.first+1 << endl;
}