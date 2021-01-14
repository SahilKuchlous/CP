#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct range {
	int id;
	int s, e;
	bool operator < (const range r) const {
		return s < r.s;
	}
};
int n, k;
range ranges[1000000];
vector<int> times;
int segtree[8000000];
void update (int x, int l, int r, int p) {
	if (p < l || p > r) {
		return;
	}
	segtree[x]++;
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p);
	update(2*x+2, m+1, r, p);
}
int query (int x, int l, int r, int s) {
	if (l == r) {
		return l;
	}
	int m = (l+r)/2;
	if (s+segtree[2*x+2] >= k) {
		return query(2*x+2, m+1, r, s);
	} else {
		return query(2*x+1, l, m, s+segtree[2*x+2]);
	}
}
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> ranges[i].s >> ranges[i].e;
		ranges[i].id = i+1;
		times.push_back(ranges[i].e);
	}
	sort(ranges, ranges+n);
	sort(times.begin(), times.end());
	times.resize(unique(times.begin(), times.end())-times.begin());
	int prev = -1;
	int o = 0;
	int ind = -1;
	for (int i=0; i<n; i++) {
		if (prev > -1 && ranges[i].s > prev && i >= k) {
			int score = times[query(0, 0, times.size()-1, 0)]-prev;
			if (score > o) {
				o = score;
				ind = i;
			}
		}
		int pos = lower_bound(times.begin(), times.end(), ranges[i].e) - times.begin();
		update(0, 0, times.size()-1, pos);
		prev = ranges[i].s;
	}
	int score = times[query(0, 0, times.size()-1, 0)]-prev;
	if (score > o) {
		o = score;
		ind = n;
	}
	cout << o << endl;
	if (ind > -1) {
		set< pair<int, int> > track;
		for (int i=0; i<ind; i++) {
			track.insert(make_pair(-ranges[i].e, ranges[i].id));
		}
		for (int i=0; i<k; i++) {
			cout << track.begin()->second << " ";
			track.erase(track.begin());
		}
		cout << endl;
	}
}