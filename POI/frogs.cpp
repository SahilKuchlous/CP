#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int wx, wy;
int sx, sy, ex, ey;
int n;
pair<int, int> pos[1000000];
int dist[1000][1000];
set< pair<int, pair<int, int> > > ord;
pair<int, int> st[1000][1000];
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector< pair<int, pair<int, int> > > ord2;
bool on[1000][1000];
int par[1000000];
int o = 0;
int root (int x) {
	while (x != par[x]) {
		par[x] = par[par[x]];
		x = par[x];
	}
	return x;
}
void merge (int x, int y) {
	int r1 = root(x), r2 = root(y);
	if (r1 == r2) return;
	par[r2] = r1;
}
int calc (int x1, int y1, int x2, int y2) {return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);};
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> wx >> wy;
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> pos[i].first >> pos[i].second;
		pos[i].first--; pos[i].second--;
	}
	for (int i=0; i<wx; i++) {
		for (int j=0; j<wy; j++) {
			dist[i][j] = 1e8;
		}
	}
	for (int i=0; i<n; i++) {
		dist[pos[i].first][pos[i].second] = 0;
		ord.insert(make_pair(0, pos[i]));
		st[pos[i].first][pos[i].second] = pos[i];
	}
	while (ord.size() > 0) {
		pair<int, int> cur = ord.begin()->second;
		ord.erase(ord.begin());
		for (int i=0; i<4; i++) {
			int nx = cur.first+dx[i], ny = cur.second+dy[i];
			if (nx < 0 || nx >= wx || ny < 0 || ny >= wy) continue;
			int cur_d = calc(st[cur.first][cur.second].first, st[cur.first][cur.second].second, nx, ny);
			if (cur_d < dist[nx][ny]) {
				ord.erase(make_pair(dist[nx][ny], make_pair(nx, ny)));
				dist[nx][ny] = cur_d;
				ord.insert(make_pair(dist[nx][ny], make_pair(nx, ny)));
				st[nx][ny] = st[cur.first][cur.second];
			}
		}
	}
	for (int i=0; i<wx; i++) {
		for (int j=0; j<wy; j++) {
			ord2.push_back(make_pair(-dist[i][j], make_pair(i, j)));
			par[i*wy+j] = i*wy+j;
		}
	}
	sort(ord2.begin(), ord2.end());
	for (int i=0; i<ord2.size(); i++) {
		pair<int, int> cur = ord2[i].second;
		on[cur.first][cur.second] = true;
		for (int i=0; i<4; i++) {
			int nx = cur.first+dx[i], ny = cur.second+dy[i];
			if (nx < 0 || nx >= wx || ny < 0 || ny >= wy) continue;
			if (on[nx][ny]) merge(cur.first*wy+cur.second, nx*wy+ny);
		}
		if (root(sx*wy+sy) == root(ex*wy+ey)) {
			o = -ord2[i].first;
			break;
		}
	}
	cout << o << endl;
}