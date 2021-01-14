#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		int x, y;
		cin >> x >> y;
		string moves;
		cin >> moves;
		int o = -1;
		int t = 1;
		for (auto i: moves) {
			if (i == 'N') y++;
			if (i == 'S') y--;
			if (i == 'E') x++;
			if (i == 'W') x--;
			if (abs(x)+abs(y) <= t) {
				o = t;
				break;
			}
			t++;
		}
		cout << "Case #" << z << ": ";
		if (o > -1) {
			cout << o << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}