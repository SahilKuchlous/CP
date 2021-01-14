#include <iostream>
using namespace std;
int main () {
	char z[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int t;
	cin >> t;
	while (t--) {
		int r, c, k;
		cin >> r >> c >> k;
		char a[r][c];
		int e = 0;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'R') {
					e++;
				}
			}
		}
		char o[r][c];
		int x = e%k;
		int n = 0;
		int d = e/k;
		int y = 0;
		bool l = true;
		int b;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (l) {
					b = j;
				} else {
					b = c-j-1;
				}
				o[i][b] = z[n];
				if (a[i][b] == 'R') {
					y++;
				}
				if ((y == d && x <= 0) || (y == d+1 && x > 0)) {
					if (n < k-1) {
						n++;
					}
					y = 0;
					x--;
				}
			}
			l = !l;
		}
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				cout << o[i][j];
			}
			cout << endl;
		}
	}
}