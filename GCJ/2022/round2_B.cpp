#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cout << "Case #" << test+1 << ": ";
		int r;
		cin >> r;
		bool correct[2*r+1][2*r+1];
		bool incorrect[2*r+1][2*r+1];
		for (int i=0; i<2*r+1; i++) {
			for (int j=0; j<2*r+1; j++) {
				correct[i][j] = incorrect[i][j] = false;
			}
		}
		for (int x=-r; x<=r; x++) {
			for (int y=-r; y<=r; y++) {
				if (round(sqrt(x*x + y*y)) <= r) {
					correct[x+r][y+r] = true;
				}
			}
		}
		for (int nr=0; nr<=r; nr++) {
			for (int x=-nr; x<=nr; x++) {
				int y = round(sqrt(nr*nr-x*x));
				incorrect[x+r][y+r] = true;
				incorrect[x+r][-y+r] = true;
				incorrect[y+r][x+r] = true;
				incorrect[-y+r][x+r] = true;
			}
		}
		int cnt = 0;
		for (int i=0; i<2*r+1; i++) {
			for (int j=0; j<2*r+1; j++) {
				if (correct[i][j] != incorrect[i][j]) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}