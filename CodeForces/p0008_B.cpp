#include <iostream>
#include <string>
#include <set>
using namespace std;
int main () {
	string s;
	cin >> s;
	set< pair<int, int> > vis;
	vis.insert(make_pair(0, 0));
	int x = 0, y = 0;
	int pre_x, pre_y;
	bool o = true;
	for (auto i: s) {
		pre_x = x;
		pre_y = y;
		if (i == 'L') {
			x--;
		} else if (i == 'R') {
			x++;
		} else if (i == 'U') {
			y++;
		} else if (i == 'D') {
			y--;
		}
		if (vis.find(make_pair(x, y)) != vis.end()) {
			o = false;
			break;
		}
		if (x-1 != pre_x && vis.find(make_pair(x-1, y)) != vis.end()) {
			o = false;
			break;
		}
		if (x+1 != pre_x && vis.find(make_pair(x+1, y)) != vis.end()) {
			o = false;
			break;
		}
		if (y+1 != pre_y && vis.find(make_pair(x, y+1)) != vis.end()) {
			o = false;
			break;
		}
		if (y-1 != pre_y && vis.find(make_pair(x, y-1)) != vis.end()) {
			o = false;
			break;
		}
		vis.insert(make_pair(x, y));
	}
	if (o) {
		cout << "OK" << endl;
	} else {
		cout << "BUG" << endl;
	}
}