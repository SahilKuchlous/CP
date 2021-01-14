#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int arrs[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> arrs[i][j];
		}
	}
	int best[(int)pow(2, m)];
	int best_min;
	int best_i;
	int cur_min;
	for (int i=0; i<pow(2, m); i++) {
		best_min = -1;
		for (int j=0; j<n; j++) {
			cur_min = 1e9;
			for (int k=0; k<m; k++) {
				if (i & (1 << k)) {
					cur_min = min(cur_min, arrs[j][k]);
				}
			}
			if (cur_min >= best_min) {
				best_min = cur_min;
				best_i = j;
			}
		}
		best[i] = best_i;
	}
	best_min = -1;
	pair<int, int> best_out;
	for (int i=0; i<pow(2, m); i++) {
		for (int j=0; j<pow(2, m); j++) {
			cur_min = 1e9;
			for (int k=0; k<m; k++) {
				cur_min = min(cur_min, max(arrs[best[i]][k], arrs[best[j]][k]));
			}
			if (cur_min > best_min) {
				best_min = cur_min;
				best_out = make_pair(best[i], best[j]);
			}
		}
	}
	cout << best_out.first+1 << " " << best_out.second+1 << endl;
}