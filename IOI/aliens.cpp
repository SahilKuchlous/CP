#include <iostream>
#include <map>
using namespace std;
long long n, x0, y0;
long long lft, rt, top, bot;
map< pair<long long, long long>, bool > memo;
long long cnt = 0;
bool check (long long x, long long y) {
	cnt++;
	if (cnt == 300) cout << "solution " << x << " " << y << endl;
	if (x <= 0 || x > n || y <= 0 || y > n) return 0;
	if (memo.find(make_pair(x, y)) != memo.end()) return memo[make_pair(x, y)];
	string ans;
	cout << "examine " << x << " " << y << endl;
	cin >> ans;
	memo[make_pair(x, y)] = (ans == "true" ? 1:0);
	return memo[make_pair(x, y)];
}
void edge_left (long long p) {
	long long l = p, r = x0, m;
	long long o = -1;
	while (l <= r) {
		m = (l+r)/2;
		if (check(m, y0)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	lft = o;
}
void find_left () {
	long long cur = x0;
	long long dif = 1;
	while (cur > 0) {
		cur -= dif;
		dif *= 2;
		if (!check(cur, y0)) {
			edge_left(cur);
			return;
		}
	}
	edge_left(1);
}
void edge_right (long long p) {
	long long l = x0, r = p, m;
	long long o = -1;
	while (l <= r) {
		m = (l+r)/2;
		if (check(m, y0)) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	rt = o;
}
void find_right () {
	long long cur = x0;
	long long dif = 1;
	while (cur <= n) {
		cur += dif;
		dif *= 2;
		if (!check(cur, y0)) {
			edge_right(cur);
			return;
		}
	}
	edge_right(n);
}
void edge_bot (long long p) {
	long long l = p, r = y0, m;
	long long o = -1;
	while (l <= r) {
		m = (l+r)/2;
		if (check(x0, m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	bot = o;
}
void find_bot () {
	long long cur = y0;
	long long dif = 1;
	while (cur > 0) {
		cur -= dif;
		dif *= 2;
		if (!check(x0, cur)) {
			edge_bot(cur);
			return;
		}
	}
	edge_bot(1);
}
void edge_top (long long p) {
	long long l = y0, r = p, m;
	long long o = -1;
	while (l <= r) {
		m = (l+r)/2;
		if (check(x0, m)) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	top = o;
}
void find_top () {
	long long cur = y0;
	long long dif = 1;
	while (cur <= n) {
		cur += dif;
		dif *= 2;
		if (!check(x0, cur)) {
			edge_top(cur);
			return;
		}
	}
	edge_top(n);
}
int main () {
	cin >> n >> x0 >> y0;
	memo[make_pair(x0, y0)] = 1;
	find_left();
	find_right();
	find_bot();
	find_top();
	long long size = rt-lft+1;
	bool r1 = false;
	if (x0+2*size <= n) r1 = check(x0+2*size, y0);
	bool r2 = false;
	if (x0+4*size <= n) r2 = check(x0+4*size, y0);
	bool l1 = false;
	if (x0-2*size > 0) l1 = check(x0-2*size, y0);
	bool l2 = false;
	if (x0-4*size > 0) l2 = check(x0-4*size, y0);
	bool u1 = false;
	if (y0+2*size <= n) u1 = check(x0, y0+2*size);
	bool u2 = false;
	if (y0+4*size <= n) u2 = check(x0, y0+4*size);
	bool d1 = false;
	if (y0-2*size > 0) d1 = check(x0, y0-2*size);
	bool d2 = false;
	if (y0-4*size > 0) d2 = check(x0, y0-4*size);
	long long x_pos;
	if (l1 && !r1) x_pos = 1;
	if (r1 && !l1) x_pos = -1;
	if (l1 && l2) x_pos = 2;
	if (l1 && r1) x_pos = 0;
	if (r1 && r2) x_pos = -2;
	long long y_pos;
	if (u1 && !d1) y_pos = -1;
	if (d1 && !u1) y_pos = 1;
	if (u1 && u2) y_pos = -2;
	if (u1 && d1) y_pos = 0;
	if (d1 && d2) y_pos = 2;
	long long mid_x = lft-size*x_pos+size/2;
	long long mid_y = bot-size*y_pos+size/2;
	cout << "solution " << mid_x << " " << mid_y << endl;
}