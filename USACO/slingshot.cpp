#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
ifstream fin("slingshot.in");
ofstream fout("slingshot.out");
struct ss {
	int x, y;
	int t;
	bool operator < (const ss& str) const {
		if (x != str.x) return (x < str.x);
		return y < str.y;
	}
};
struct pile {
	int id;
	int x, y;
	bool operator < (const pile& str) const {
		if (x != str.x) return (x < str.x);
		return y < str.y;
	}
};
ss slings[100100];
pile piles[100100];
vector<int> xval, yval;
long long segtree[2][400100];
long long ans[100100];
void init () {
	for (int i=0; i<400100; i++) {
		segtree[0][i] = segtree[1][i] = 1e12;
	}
}
void update (int x, int l, int r, int p, long long v, int t) {
	if (p < l || p > r) {
		return;
	}
	segtree[t][x] = min(segtree[t][x], v);
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v, t);
	update(2*x+2, m+1, r, p, v, t);
}
long long query (int x, int l, int r, int a, int b, int t) {
	if (r < a || l > b) {
		return 1e12;
	}
	if (a <= l && r <= b) {
		return segtree[t][x];
	}
	int m = (l+r)/2;
	long long v = 1e12;
	v = min(v, query(2*x+1, l, m, a, b, t));
	v = min(v, query(2*x+2, m+1, r, a, b, t));
	return v;
}
int main () {
	int n, m;
	fin >> n >> m;
	for (int i=0; i<n; i++) {
		fin >> slings[i].x >> slings[i].y >> slings[i].t;
	}
	sort(slings, slings+n);
	for (int i=0; i<m; i++) {
		piles[i].id = i;
		fin >> piles[i].x >> piles[i].y;
	}
	sort(piles, piles+m);
	for (int i=0; i<n; i++) {
		xval.push_back(slings[i].x);
		yval.push_back(slings[i].y);
	}
	sort(xval.begin(), xval.end());
	xval.resize(unique(xval.begin(), xval.end())-xval.begin());
	sort(yval.begin(), yval.end());
	yval.resize(unique(yval.begin(), yval.end())-yval.begin());
	map<int, int> xid, yid;
	for (int i=0; i<xval.size(); i++) {
		xid[xval[i]] = i;
	}
	for (int i=0; i<yval.size(); i++) {
		yid[yval[i]] = i;
	}
	for (int i=0; i<m; i++) {
		ans[piles[i].id] = abs(piles[i].x-piles[i].y);
	}
	init();
	int cur = 0;
	for (int i=0; i<n; i++) {
		while (cur < m && piles[cur].x < slings[i].x) {
			int act_y = upper_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin()-1;
			ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, 0, act_y, 0) + (piles[cur].x+piles[cur].y));
			act_y = lower_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin();
			ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, act_y, n-1, 1) + (piles[cur].x-piles[cur].y));
			cur++;
		}
		update(0, 0, n-1, yid[slings[i].y], -slings[i].x-slings[i].y+slings[i].t, 0);
		update(0, 0, n-1, yid[slings[i].y], -slings[i].x+slings[i].y+slings[i].t, 1);
	}
	while (cur < m) {
		int act_y = upper_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin()-1;
		ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, 0, act_y, 0) + (piles[cur].x+piles[cur].y));
		act_y = lower_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin();
		ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, act_y, n-1, 1) + (piles[cur].x-piles[cur].y));
		cur++;
	}
	init();
	cur = m-1;
	for (int i=n-1; i>=0; i--) {
		while (cur >= 0 && piles[cur].x > slings[i].x) {
			int act_y = upper_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin()-1;
			ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, 0, act_y, 0) + (-piles[cur].x+piles[cur].y));
			act_y = lower_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin();
			ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, act_y, n-1, 1) + (-piles[cur].x-piles[cur].y));
			cur--;
		}
		update(0, 0, n-1, yid[slings[i].y], slings[i].x-slings[i].y+slings[i].t, 0);
		update(0, 0, n-1, yid[slings[i].y], slings[i].x+slings[i].y+slings[i].t, 1);
	}
	while (cur >= 0) {
		int act_y = upper_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin()-1;
		ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, 0, act_y, 0) + (-piles[cur].x+piles[cur].y));
		act_y = lower_bound(yval.begin(), yval.end(), piles[cur].y)-yval.begin();
		ans[piles[cur].id] = min(ans[piles[cur].id], query(0, 0, n-1, act_y, n-1, 1) + (-piles[cur].x-piles[cur].y));
		cur--;
	}
	for (int i=0; i<m; i++) {
		fout << ans[i] << endl;
	}
}