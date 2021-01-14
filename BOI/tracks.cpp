// Stack overflow
#include <iostream>
#include <vector>
using namespace std;
int h, w;
char grid[4000][4000];
bool vis[4000][4000];
vector< pair<int, int> > starts, upd;
int cnt = 0;
void dfs (int x, int y, char t) {
	cout << x << " " << y << endl;
	if (grid[x][y] == '.' || vis[x][y]) return;
	if (grid[x][y] != t) {
		upd.push_back(make_pair(x, y));
		return;
	}
	vis[x][y] = true;
	if (x > 0) dfs(x-1, y, t);
	if (x < h-1) dfs(x+1, y, t);
	if (y > 0) dfs(x, y-1, t);
	if (y < w-1) dfs(x, y+1, t);
}
int main () {
	cin >> h >> w;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> grid[i][j];
		}
	}
	starts.push_back(make_pair(0, 0));
	while (starts.size() > 0) {
		cnt++;
		for (auto i: starts) {
			dfs(i.first, i.second, grid[i.first][i.second]);
		}
		starts = upd;
		upd.clear();
	}
	cout << cnt << endl;
}