#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int pos;
	char type;
	int first_r = 0, first_b = 0;
	int prev_r = 0, prev_b = 0;
	int max_r = 0, max_b = 0;
	int prev_g = 0;
	long long o = 0;
	for (int i=0; i<n; i++) {
		cin >> pos >> type;
		if (type == 'R') {
			if (prev_r == 0) {
				first_r = prev_r = pos;
				continue;
			}
			max_r = max(max_r, pos-prev_r);
			prev_r = pos;
		} else if (type == 'B') {
			if (prev_b == 0) {
				first_b = prev_b = pos;
				continue;
			}
			max_b = max(max_b, pos-prev_b);
			prev_b = pos;
		} else {
			if (prev_g == 0) {
				if (first_r > 0) o += pos-first_r;
				if (first_b > 0) o += pos-first_b;
				prev_r = prev_b = prev_g = pos;
				max_r = max_b = 0;
				continue;
			}
			max_r = max(max_r, pos-prev_r);
			max_b = max(max_b, pos-prev_b);
			long long p1 = pos-prev_g + pos-prev_g-max_r + pos-prev_g-max_b;
			long long p2 = 2*(pos-prev_g);
			o += min(p1, p2);
			prev_r = prev_b = prev_g = pos;
			max_r = max_b = 0;
		}
	}
	if (prev_g > 0) {
		o += prev_r-prev_g;
		o += prev_b-prev_g;
	} else {
		o += prev_r-first_r;
		o += prev_b-first_b;
	}
	cout << o << endl;
}