#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1005][1005];
int main () {
	int n, m;
	cin >> n >> m;
	int ai, bi;
	int uni = 0;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		if (ai > bi) swap(ai, bi);
		if (cnt[ai][bi] == 0) uni++;
		cnt[ai][bi]++;
	}
	int best = 1e8;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			if (cnt[i][j] > 0) best = min(best, cnt[i][j]);
		}
	}
	if (uni < n-1) {
		cout << 0 << endl;
	} else {
		cout << best << endl;
	}
}