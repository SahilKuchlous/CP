// #pragma GCC optimize("Ofast")
#include <iostream>
#include <bitset>
using namespace std;
int n, m, l;
bitset<500> grid[500], cur[500], temp[500];
char dir[5000];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> l;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			if (inp == '.') grid[i][j] = cur[i][j] = 1;
		}
	}
	for (int i=0; i<l; i++) {
		cin >> dir[i];
	}
	for (int k=0; k<l; k++) {
		if (dir[k] == 'N') {
			for (int i=0; i<n-1; i++) {
				cur[i] = cur[i+1];
			}
			cur[n-1].reset();
		}
		if (dir[k] == 'S') {
			for (int i=n-1; i>0; i--) {
				cur[i] = cur[i-1];
			}
			cur[0].reset();
		}
		if (dir[k] == 'E') {
			for (int i=0; i<n; i++) {
				cur[i] <<= 1;
			}
		}
		if (dir[k] == 'W') {
			for (int i=0; i<n; i++) {
				cur[i] >>= 1;
			}
		}
		if (dir[k] == '?') {
			for (int i=0; i<n; i++) {
				temp[i] = ((cur[i] << 1) | (cur[i] >> 1));
			}
			for (int i=0; i<n-1; i++) {
				temp[i] |= cur[i+1];
			}
			for (int i=1; i<n; i++) {
				temp[i] |= cur[i-1];
			}
			for (int i=0; i<n; i++) {
				cur[i] = temp[i];
			}
		}
		for (int i=0; i<n; i++) {
			cur[i] &= grid[i];
		}
	}
	int o = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			o += cur[i][j];
		}
	}
	cout << o << endl;
}