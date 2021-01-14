#include <iostream>
#define ll long long
using namespace std;
int main () {
	while (true) {
		ll n, p;
		cin >> n >> p;
		if (n==0 && p==0) {
			break;
		}
		ll x, y;
		x = (n+1)/2;
		y = (n+1)/2;
		int dir = 0;
		int d = 1;
		ll c = 0;
		bool done = false;
		while (true) {
			if (c+d < p) {
				c += d;
				if (dir == 0) {
					y+=d;
				} else if (dir == 1) {
					x-=d;
				} else if (dir == 2) {
					y-=d;
				} else if (dir == 3) {
					x+=d;
				}
			} else {
				for (int i=0; i<d; i++) {
					c++;
					if (c == p) {
						done = true;
						break;
					}
					if (dir == 0) {
						y++;
					} else if (dir == 1) {
						x--;
					} else if (dir == 2) {
						y--;
					} else if (dir == 3) {
						x++;
					}
				}
				if (done) {
					break;
				}
			}
			dir = (dir+1)%4;
			if (dir == 0 || dir == 2) {
				d++;
			}
		}
		cout << "Line = " << y << ", column = " << x << "." << endl;
	}
}