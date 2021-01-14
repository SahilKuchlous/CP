#include <iostream>
using namespace std;
int main () {
	long long h, root_x, root_y, q;
	cin >> h >> root_x >> root_y >> q;
	long long rows[h+1];
	rows[0] = root_x;
	for (int i=1; i<=h; i++) {
		int width = 6*(1<<(h-i))-1;
		rows[i] = rows[i-1] + (width/2)/2+1;
	}
	long long x1, y1, x2, y2, o;
	for (int i=0; i<q; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		o = 0;
		if (x1 <= root_x && x2 >= root_x && y1 <= root_y && y2 >= root_y) o++;
		for (int j=1; j<h; j++) {
			if (x1 <= rows[j] && rows[j] <= x2) {
				long long dist = 2*(rows[j]-rows[j-1]);
				long long s = root_y-(rows[j]-root_x);
				if (y1 > s) {
					s = y1-((y1-s)%dist);
					if ((y1-s)%dist != 0) s += dist;
				}
				long long e = root_y+(rows[j]-root_x);
				if (y2 < e) {
					e = y2+((e-y2)%dist);
					if ((e-y2)%dist != 0) e -= dist;
				}
				o += ((e-s)/dist)+1;
			}
		}
		if (x1 <= rows[h] && rows[h] <= x2) {
			long long dist = 6;
			long long s = root_y-(rows[h]-root_x);
			if (y1 > s) {
				s = y1-((y1-s)%dist);
				if ((y1-s)%dist > 0 && (y1-s)%dist < 5) o++;
				if ((y1-s)%dist != 0) s += dist;
			}
			long long e = root_y+(rows[h]-root_x)-4;
			if (y2 < e) {
				e = y2+((e-y2)%dist);
				if ((e-y2)%dist != 0) e -= dist;
			}
			if (y2-e < 4) o--;
			o += (((e-s)/dist)+1)*2;
		}
		cout << o << endl;
	}
}