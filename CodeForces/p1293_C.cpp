#include <iostream>
using namespace std;
int main () {
	int n, q;
	cin >> n >> q;
	bool block[n+1][2];
	int num[n+1][2];
	for (int i=1; i<=n; i++) {
		block[i][0] = block[i][1] = false;
		num[i][0] = num[i][1] = 0;
	}
	long long count = 0;
	int r, c;
	for (int i=0; i<q; i++) {
		cin >> c >> r;
		c--;
		if (c == 0) {
			if (block[r][c]) {
				// cout << "A" << endl;
				num[r][c] = 0;
				for (int i=max(1, r-1); i<=min(n, r+1); i++) {
					if (block[i][1]) {
						num[i][1]--;
						count--;
					}
				}
			} else {
				// cout << "B" << endl;
				for (int i=max(1, r-1); i<=min(n, r+1); i++) {
					if (block[i][1]) {
						num[r][c]++;
						num[i][1]++;
						count++;
					}
				}
			}
		} else {
			if (block[r][c]) {
				num[r][c] = 0;
				for (int i=max(1, r-1); i<=min(n, r+1); i++) {
					if (block[i][0]) {
						num[i][0]--;
						count--;
					}
				}
			} else {
				for (int i=max(1, r-1); i<=min(n, r+1); i++) {
					if (block[i][0]) {
						num[r][c]++;
						num[i][0]++;
						count++;
					}
				}
			}
		}
		block[r][c] = !block[r][c];
		if (count == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}