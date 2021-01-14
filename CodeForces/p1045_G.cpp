#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100005
int n, k;
struct robot {
	int pos, rad, iq;
	bool operator < (const robot r) const {
		return rad > r.rad;
	}
};
robot a[MAXN];
vector<int> iqs;
vector<int> pts[MAXN];
vector<int> segtree[MAXN];
void update (int id, int x, int l, int r, int p, int v) {
	if (p < l || p > r) return;
	segtree[id][x] += v;
	if (l == r) return;
	int m = (l+r)/2;
	update(id, 2*x+1, l, m, p, v);
	update(id, 2*x+2, m+1, r, p, v);
}
int query (int id, int x, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return segtree[id][x];
	int m = (l+r)/2;
	return query(id, 2*x+1, l, m, a, b)+query(id, 2*x+2, m+1, r, a, b);
}
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].pos >> a[i].rad >> a[i].iq;
		iqs.push_back(a[i].iq);
	}
	sort(a, a+n);
	sort(iqs.begin(), iqs.end());
	iqs.erase(unique(iqs.begin(), iqs.end()), iqs.end());
	for (int i=0; i<n; i++) {
		int ind = lower_bound(iqs.begin(), iqs.end(), a[i].iq)-iqs.begin();
		pts[ind].push_back(a[i].pos);
	}
	for (int i=0; i<n; i++) {
		sort(pts[i].begin(), pts[i].end());
		pts[i].erase(unique(pts[i].begin(), pts[i].end()), pts[i].end());
		for (int j=0; j<4*pts[i].size(); j++) {
			segtree[i].push_back(0);
		}
	}
	for (int i=0; i<n; i++) {
		int cur_iq = lower_bound(iqs.begin(), iqs.end(), a[i].iq)-iqs.begin();
		int l_iq = lower_bound(iqs.begin(), iqs.end(), a[i].iq-k)-iqs.begin();
		int r_iq = upper_bound(iqs.begin(), iqs.end(), a[i].iq+k)-iqs.begin()-1;
		for (int j=l_iq; j<=r_iq; j++) {
			int l = lower_bound(pts[j].begin(), pts[j].end(), a[i].pos-a[i].rad)-pts[j].begin();
			int r = upper_bound(pts[j].begin(), pts[j].end(), a[i].pos+a[i].rad)-pts[j].begin()-1;
			o += query(j, 0, 0, pts[j].size()-1, l, r);
		}
		int ind = lower_bound(pts[cur_iq].begin(), pts[cur_iq].end(), a[i].pos)-pts[cur_iq].begin();
		update(cur_iq, 0, 0, pts[cur_iq].size()-1, ind, 1);
	}
	cout << o << endl;
}