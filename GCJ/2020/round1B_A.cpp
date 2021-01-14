#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
bool pos = true;
char o[40];
void check (set<int> bx, set<int> by, char x_for, char x_rev, char y_for, char y_rev, int max_x, int max_y, bool xc, bool yc) {
	int prev_on = -1, prev_type, prev_rev = -1e8;
	bool prev_flip = false;
	for (int i=0; i<=max(max_x, max_y); i++) {
		if (bx.find(i) != bx.end() && by.find(i) != by.end()) {
			pos = false;
			break;
		}
		if (bx.find(i) == bx.end() && by.find(i) == by.end()) {
			if (prev_on == -1) {
				pos = false;
				break;
			}
			if (prev_on == i-1) {
				o[i-1] = (prev_type == 0 ? (prev_flip ? x_for : x_rev) : (prev_flip ? y_for : y_rev));
			}
			o[i] = (prev_type == 0 ? (prev_flip ? x_for : x_rev) : (prev_flip ? y_for : y_rev));
			prev_rev = i;
			continue;
		}
		if (prev_rev == i-1) {
			o[i-1] = (prev_type == 0 ? (prev_flip ? x_rev : x_for) : (prev_flip ? y_rev : y_for));
		}
		prev_on = i;
		if (bx.find(i) != bx.end() && by.find(i) == by.end()) {
			o[i] = (xc && i == max_x) ? x_rev : x_for;
			if (xc && i == max_x) {
				prev_flip = true;
			} else {
				prev_flip = false;
			}
			prev_type = 0;
		}
		if (bx.find(i) == bx.end() && by.find(i) != by.end()) {
			o[i] = (yc && i == max_y) ? y_rev : y_for;
			if (yc && i == max_y) {
				prev_flip = true;
			} else {
				prev_flip = false;
			}
			prev_type = 1;
		}
	}
}
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		cout << "Case #" << z << ": ";
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			continue;
		}
		char x_for = 'E', x_rev = 'W', y_for = 'N', y_rev = 'S';
		if (x < 0) {
			x_for = 'W';
			x_rev = 'E';
		}
		if (y < 0) {
			y_for = 'S';
			y_rev = 'N';
		}
		x = abs(x);
		y = abs(y);
		set<int> x_reg, x_comp, y_reg, y_comp;
		int max_x = 0, max_y = 0;
		for (int i=0; i<=30; i++) {
			if (x&(1<<i)) {
				x_reg.insert(i);
				max_x = i;
			}
			if (y&(1<<i)) {
				y_reg.insert(i);
				max_y = i;
			}
		}
		x_comp.insert(max_x+1);
		bool first_x = false;
		for (int i=0; i<=max_x; i++) {
			if (x_reg.find(i) != x_reg.end()) {
				if (!first_x) x_comp.insert(i);
				first_x = true;
			} else {
				if (first_x) x_comp.insert(i);
			}
		}
		y_comp.insert(max_y+1);
		bool first_y = false;
		for (int i=0; i<=max_y; i++) {
			if (y_reg.find(i) != y_reg.end()) {
				if (!first_y) y_comp.insert(i);
				first_y = true;
			} else {
				if (first_y) y_comp.insert(i);
			}
		}
		pos = true;
		check(x_reg, y_reg, x_for, x_rev, y_for, y_rev, max_x, max_y, false, false);
		if (pos) {
			for (int i=0; i<=max(max_x, max_y); i++) {
				cout << o[i];
			}
			cout << endl;
			continue;
		}
		if (max_x < max_y) {
			pos = true;
			check(x_comp, y_reg, x_rev, x_for, y_for, y_rev, max_x+1, max_y, true, false);
			if (pos) {
				for (int i=0; i<=max(max_x+1, max_y); i++) {
					cout << o[i];
				}
				cout << endl;
				continue;
			}
			pos = true;
			check(x_reg, y_comp, x_for, x_rev, y_rev, y_for, max_x, max_y+1, false, true);
			if (pos) {
				for (int i=0; i<=max(max_x, max_y+1); i++) {
					cout << o[i];
				}
				cout << endl;
				continue;
			}
		} else {
			pos = true;
			check(x_reg, y_comp, x_for, x_rev, y_rev, y_for, max_x, max_y+1, false, true);
			if (pos) {
				for (int i=0; i<=max(max_x, max_y+1); i++) {
					cout << o[i];
				}
				cout << endl;
				continue;
			}
			pos = true;
			check(x_comp, y_reg, x_rev, x_for, y_for, y_rev, max_x+1, max_y, true, false);
			if (pos) {
				for (int i=0; i<=max(max_x+1, max_y); i++) {
					cout << o[i];
				}
				cout << endl;
				continue;
			}
		}
		pos = true;
		check(x_comp, y_comp, x_rev, x_for, y_rev, y_for, max_x+1, max_y+1, true, true);
		if (pos) {
			for (int i=0; i<=max(max_x+1, max_y+1); i++) {
				cout << o[i];
			}
			cout << endl;
			continue;
		}
		cout << "IMPOSSIBLE" << endl;
	}
}