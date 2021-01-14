#include <iostream>
#include <cmath>
using namespace std;
int a[1000000];
int seg[1000][3];
int n, m, x;
/*
int nice () {
	int o = 1;
	int l = 1;
	for (int i=1; i<n; i++) {
		if (a[i]-a[i-1] == 1) {
			l++;
			if (l > o) {
				o = l;
			}
		} else {
			l = 1;
		}
	}
	return o;
}
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << nice() << endl;
	int x, y;
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		a[x-1] = y;
		cout << nice() << endl;
	}
}
*/

void update (int y) {
	int o = 1;
	int l = 1;
	for (int i=y*x+1; i<min(n,(y+1)*x); i++) {
		if (a[i]-a[i-1] == 1) {
			l++;
			if (l > o) {
				o = l;
			}
		} else {
			l = 1;
		}
	}
	seg[y][0] = o;
	o = 1;
	for (int i=y*x+1; i<min(n,(y+1)*x); i++) {
		if (a[i]-a[i-1] == 1) {
			o++;
		} else {
			break;
		}
	}
	seg[y][1] = o;
	o = 1;
	for (int i=min(n,(y+1)*x)-1; i>y*x; i--) {
		if (a[i]-a[i-1] == 1) {
			o++;
		} else {
			break;
		}
	}
	seg[y][2] = o;
}

int query () {
	int i = 0;
	int o = 0;
	int s = 0;
	while (i < ceil(n*1.0/x)) {
		if (seg[i][0] > o) {
			o = seg[i][0];
		}
		s = seg[i][2];
		bool e = false;
		while (true) {
			if (i == ceil(n*1.0/x)-1) {
				break;
			}
			if (a[(i+1)*x]-a[(i+1)*x-1] == 1) {
				e = true;
				i++;
				s += seg[i][1];
				if (seg[i][1] != x) {
					break;
				}
			} else {
				break;
			}
		}
		if (s > o) {
			o = s;
		}
		if (!e) {
			i++;
		}
	}
	return o;
}

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	x = floor(sqrt(n));
	for (int i=0; i<ceil(n*1.0/x); i++) {
		update(i);
		// cout << seg[i][0] << " " << seg[i][1] << " " << seg[i][2] << endl;
	}
	cout << query() << endl;
	int y, z;
	for (int i=0; i<m; i++) {
		cin >> y >> z;
		y--;
		a[y] = z;
		update(y/x);
		cout << query() << endl;
	}
}






