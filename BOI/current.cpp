#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
struct seg {
	int id;
	int start, end;
	bool wrap = false;
	bool operator < (const seg s) const {
		return start < s.start;
	}
};
int comp (int p1, bool w1, int p2, bool w2) {
	if (w1) p1 += m;
	if (w2) p2 += m;
	return p1-p2;
}
int main () {
	cin >> m >> n;
	seg segs[n];
	for (int i=0; i<n; i++) {
		cin >> segs[i].start >> segs[i].end;
		segs[i].id = i;
		if (segs[i].start > segs[i].end) segs[i].wrap = true;
	}
	int o[n];
	sort(segs, segs+n);
	int init_a = segs[0].start;
	int cur_a = segs[0].end;
	bool wrap_a = false;
	if (cur_a < init_a) wrap_a = true;
	o[segs[0].id] = 0;
	int init_b = segs[1].start;
	int cur_b = segs[1].end;
	bool wrap_b = false;
	if (cur_b < init_b) wrap_b = true;
	o[segs[1].id] = 1;
	bool pos = true;
	for (int i=2; i<n; i++) {
		// cout << cur_a << " " << wrap_a << " " << cur_b << " " << wrap_b << endl;
		// cout << segs[i].start << " " << segs[i].end << endl;
		if (comp(cur_a, wrap_a, cur_b, wrap_b) > 0) {
			o[segs[i].id] = 1;
			if (comp(segs[i].start, false, cur_b, wrap_b) > 1) {
				pos = false;
				break;
			}
			if (comp(segs[i].end, segs[i].wrap, cur_b, wrap_b) > 0) {
				cur_b = segs[i].end;
				wrap_b = segs[i].wrap;
			}
		} else {
			o[segs[i].id] = 0;
			if (comp(segs[i].start, false, cur_a, wrap_a) > 1) {
				pos = false;
				break;
			}
			if (comp(segs[i].end, segs[i].wrap, cur_a, wrap_a) > 0) {
				cur_a = segs[i].end;
				wrap_a = segs[i].wrap;
			}
		}
	}
	cout << cur_a << " " << wrap_a << " " << cur_b << " " << wrap_b << endl;
	if (comp(init_a, true, cur_a, wrap_a) > 1) pos = false;
	if (comp(init_b, true, cur_b, wrap_b) > 1) pos = false;
	if (pos) {
		for (int i=0; i<n; i++) {
			cout << o[i];
		}
		cout << endl;
	} else {
		cout << "impossible" << endl;
	}
}