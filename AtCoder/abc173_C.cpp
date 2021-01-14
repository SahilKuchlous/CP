#include <iostream>
using namespace std;
int main () {
	int h, w, k;
	cin >> h >> w >> k;
	char grid[h][w];
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	for (int i=0; i<(1<<h); i++) {
		for (int j=0; j<(1<<w); j++) {
			int cnt = 0;
			for (int x=0; x<h; x++) {
				for (int y=0; y<w; y++) {
					if ((i & (1<<x)) || (j & (1<<y))) continue;
					if (grid[x][y] == '#') cnt++;
				}
			}
			if (cnt == k) ans++;
		}
	}
	cout << ans << endl;
}