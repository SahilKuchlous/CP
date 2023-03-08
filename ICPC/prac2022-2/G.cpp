#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAXN 100005
#define MAXM 1000000005
int n;
vector< pair<int, int> > x_lines;
vector< pair<int, int> > y_lines;

long long calc_x (int val) {
	long long o = 0;
	for (auto i: x_lines) {
		if (i.second < val) {
			o += val-i.second;
		} else if (i.first > val) {
			o += i.first-val;
		}
	}
	return o;
}

long long calc_y (int val) {
	long long o = 0;
	for (auto i: y_lines) {
		if (i.second < val) {
			o += val-i.second;
		} else if (i.first > val) {
			o += i.first-val;
		}
	}
	return o;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		x_lines.clear();
		y_lines.clear();
		int a, b, c, d;
		for (int i=0; i<n; i++) {
			cin >> a >> b >> c >> d;
			x_lines.push_back(make_pair(a, c));
			y_lines.push_back(make_pair(b, d));
		}

		long long ans = 0;

		int l = 0, r = MAXM, m1, m2;
		while (l < r) {
			m1 = l + floor(1.0*(r-l)/3);
			m2 = l + ceil(2.0*(r-l)/3);
			long long s1 = calc_x(m1);
			long long s2 = calc_x(m2);
			if (s1 <= s2) {
				r = m2-1;
			} else {
				l = m1+1;
			}
		}
		ans += calc_x(l);

		l = 0; r = MAXM;
		while (l < r) {
			m1 = l + floor(1.0*(r-l)/3);
			m2 = l + ceil(2.0*(r-l)/3);
			long long s1 = calc_y(m1);
			long long s2 = calc_y(m2);
			if (s1 <= s2) {
				r = m2-1;
			} else {
				l = m1+1;
			}
		}
		ans += calc_y(l);

		cout << ans << endl;
	}
}