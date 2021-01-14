#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
struct rect {
	long long x, y, a;
	bool operator < (const rect& r) const {
		return x < r.x;
	}
};
struct line {
	long long m, c;
	long long eval (long long x) {
		return m*x + c;
	}
	long double x_int (line& l) {
		return (long double) (c-l.c)/(l.m-m);
	}
};
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	rect rects[n];
	for (int i=0; i<n; i++) {
		cin >> rects[i].x >> rects[i].y >> rects[i].a;
	}
	sort(rects, rects+n);
	deque<line> dq;
	dq.push_front({0, 0});
	long long ans = 0;
	for (int i=0; i<n; i++) {
		while (dq.size() >= 2 && dq.back().eval(rects[i].y) <= dq[dq.size()-2].eval(rects[i].y)) {
			dq.pop_back();
		}
		long long f = rects[i].x*rects[i].y-rects[i].a + dq.back().eval(rects[i].y);
		ans = max(ans, f);
		line cur = {-rects[i].x, f};
		while (dq.size() >= 2 && cur.x_int(dq[0]) >= cur.x_int(dq[1])) {
			dq.pop_front();
		}
		dq.push_front(cur);
	} 
	cout << ans << endl;
}