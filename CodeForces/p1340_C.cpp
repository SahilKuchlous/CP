#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int pos[m];
	for (int i=0; i<m; i++) {
		cin >> pos[i];
	}
	int g, r;
	cin >> g >> r;
	sort(pos, pos+m);
	long long ans = 1e14;
	deque< pair<int, int> > dq;
	int dist[m*g];
	for (int i=0; i<m*g; i++) {
		dist[i] = -1;
	}
	dq.push_front(make_pair(0, 0));
	dist[0] = 0;
	pair<int, int> cur;
	int new_dist;
	while (dq.size() > 0) {
		cur = dq.front();
		dq.pop_front();
		if (cur.second + n - pos[cur.first] <= g) {
			ans = min(ans, (long long)dist[cur.first*g+cur.second]*(g+r)+cur.second+n-pos[cur.first]);
		}
		if (cur.first > 0) {
			new_dist = cur.second+pos[cur.first]-pos[cur.first-1];
			if (new_dist < g && dist[(cur.first-1)*g + new_dist] == -1) {
				dist[(cur.first-1)*g + new_dist] = dist[cur.first*g+cur.second];
				dq.push_front(make_pair(cur.first-1, new_dist));
			}
			if (new_dist == g && dist[(cur.first-1)*g] == -1) {
				dist[(cur.first-1)*g] = dist[cur.first*g+cur.second]+1;
				dq.push_back(make_pair(cur.first-1, 0));
			}
		}
		if (cur.first < m-1) {
			new_dist = cur.second+pos[cur.first+1]-pos[cur.first];
			if (new_dist < g && dist[(cur.first+1)*g + new_dist] == -1) {
				dist[(cur.first+1)*g + new_dist] = dist[cur.first*g+cur.second];
				dq.push_front(make_pair(cur.first+1, new_dist));
			}
			if (new_dist == g && dist[(cur.first+1)*g] == -1) {
				dist[(cur.first+1)*g] = dist[cur.first*g+cur.second]+1;
				dq.push_back(make_pair(cur.first+1, 0));
			}
		}
	}
	cout << (ans==1e14?-1:ans) << endl;
}