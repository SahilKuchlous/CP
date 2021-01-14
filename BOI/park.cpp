// left, down, right, top
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct tree {
	int x, y;
	long long rad;
};
double dist (int x1, int y1, int x2, int y2) {
	return sqrt(1ll*(x2-x1)*(x2-x1) + 1ll*(y2-y1)*(y2-y1));
}
int n, m, w, h;
tree trees[2100];
priority_queue< pair< double, pair<int, int> > > pq;
pair< pair<int, int>, int > qry[100100];
int par[2100];
string o[100100];
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void merge (int x, int y) {
	int r1 = root(x), r2 = root(y);
	if (r1 == r2) return;
	par[r2] = r1;
}
int main () {
	cin >> n >> m >> w >> h;
	for (int i=0; i<n; i++) {
		cin >> trees[i].x >> trees[i].y >> trees[i].rad;
		for (int j=0; j<i; j++) {
			pq.push(make_pair(-dist(trees[i].x, trees[i].y, trees[j].x, trees[j].y) + trees[i].rad + trees[j].rad, make_pair(i, j)));
		}
		pq.push(make_pair(-trees[i].x+trees[i].rad, make_pair(i, n)));
		pq.push(make_pair(-trees[i].y+trees[i].rad, make_pair(i, n+1)));
		pq.push(make_pair(-w+trees[i].x+trees[i].rad, make_pair(i, n+2)));
		pq.push(make_pair(-h+trees[i].y+trees[i].rad, make_pair(i, n+3)));
	}
	for (int i=0; i<m; i++) {
		cin >> qry[i].first.first >> qry[i].first.second;
		qry[i].second = i;
		o[i] = "";
	}
	sort(qry, qry+m);
	for (int i=0; i<n+4; i++) {
		par[i] = i;
	}
	for (int i=0; i<m; i++) {
		while (pq.size() > 0 && -pq.top().first < qry[i].first.first*2) {
			merge(pq.top().second.first, pq.top().second.second);
			pq.pop();
		}
		if (qry[i].first.second == 1) {
			o[qry[i].second] += "1";
			if (root(n) != root(n+1) && root(n+1) != root(n+2) && root(n+1) != root(n+3)) o[qry[i].second] += "2";
			if (root(n) != root(n+1) && root(n+2) != root(n+3) && root(n+1) != root(n+3) && root(n) != root(n+2)) o[qry[i].second] += "3";
			if (root(n) != root(n+1) && root(n) != root(n+3) && root(n) != root(n+2)) o[qry[i].second] += "4";
		} else if (qry[i].first.second == 2) {
			if (root(n+1) != root(n+2) && root(n) != root(n+1) && root(n+1) != root(n+3)) o[qry[i].second] += "1";
			o[qry[i].second] += "2";
			if (root(n+1) != root(n+2) && root(n+2) != root(n+3) && root(n) != root(n+2)) o[qry[i].second] += "3";
			if (root(n+1) != root(n+2) && root(n) != root(n+3) && root(n+1) != root(n+3) && root(n) != root(n+2)) o[qry[i].second] += "4";
		} else if (qry[i].first.second == 3) {
			if (root(n+2) != root(n+3) && root(n) != root(n+1) && root(n+1) != root(n+3) && root(n) != root(n+2)) o[qry[i].second] += "1";
			if (root(n+2) != root(n+3) && root(n+1) != root(n+2) && root(n) != root(n+2)) o[qry[i].second] += "2";
			o[qry[i].second] += "3";
			if (root(n+2) != root(n+3) && root(n) != root(n+3) && root(n+1) != root(n+3)) o[qry[i].second] += "4";
		} else if (qry[i].first.second == 4) {
			if (root(n) != root(n+3) && root(n) != root(n+1) && root(n) != root(n+2)) o[qry[i].second] += "1";
			if (root(n) != root(n+3) && root(n+1) != root(n+2) && root(n) != root(n+2) && root(n+1) != root(n+3)) o[qry[i].second] += "2";
			if (root(n) != root(n+3) && root(n+2) != root(n+3) && root(n+1) != root(n+3)) o[qry[i].second] += "3";
			o[qry[i].second] += "4";
		}
	}
	for (int i=0; i<m; i++) {
		cout << o[i] << endl;
	}
}