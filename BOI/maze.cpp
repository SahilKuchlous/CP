#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int, int> > adj[400100];
int dist[400100][2];
int main () {
	int w, h;
	cin >> w >> h;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	char ti;
	int t;
	for (int i=0; i<2*h+1; i++) {
		if (i%2 == 0) {
			for (int j=0; j<w; j++) {
				cin >> ti;
				if (ti == 'n') continue;
				t = (ti=='w'?0:1);
				adj[i/2*600+j].push_back(make_pair(i/2*600+j+1, t));
				adj[i/2*600+j+1].push_back(make_pair(i/2*600+j, t));
			}
		} else {
			for (int j=0; j<2*w+1; j++) {
				cin >> ti;
				if (ti == 'n') continue;
				t = (ti=='w'?0:1);
				if (j%2 == 0) {
					adj[i/2*600+j/2].push_back(make_pair((i+1)/2*600+j/2, t));
					adj[(i+1)/2*600+j/2].push_back(make_pair(i/2*600+j/2, t));
				} else {
					adj[i/2*600+(j+1)/2].push_back(make_pair((i+1)/2*600+j/2, t));
					adj[(i+1)/2*600+j/2].push_back(make_pair(i/2*600+(j+1)/2, t));
				}
			}
		}
	}
	queue< pair<int, int> > q;
	for (int i=0; i<=h; i++) {
		for (int j=0; j<=w; j++) {
			dist[i*600+j][0] = dist[i*600+j][1] = 1e8;
		}
	}
	q.push(make_pair(sy*600+sx, 0));
	q.push(make_pair(sy*600+sx, 1));
	dist[sy*600+sx][0] = dist[sy*600+sx][1] = 0;
	pair<int, int> cur;
	while (q.size() > 0) {
		cur = q.front();
		q.pop();
		for (auto i: adj[cur.first]) {
			if (dist[i.first][i.second] == 1e8 && i.second != cur.second) {
				dist[i.first][i.second] = dist[cur.first][cur.second]+1;
				q.push(i);
			}
		}
	}
	cout << min(dist[ey*600+ex][0], dist[ey*600+ex][1]) << endl;
}