#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[600005];
vector<int> pos[600005];
int pre[600005][20];
int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
		for (int j=0; j<20; j++) {
			pre[i][j] = pre[i-1][j];
			if (a[i] & (1<<j)) pre[i][j]++;
		}
	}
	int s, e;
	for (int i=0; i<m; i++) {
		cin >> s >> e;
		s--;
		int best = 0;
		for (int j=0; j<20; j++) {
			if (pre[e][j]-pre[s][j] > (e-s)/2) best += (1<<j);
		}
		if (upper_bound(pos[best].begin(), pos[best].end(), e)-upper_bound(pos[best].begin(), pos[best].end(), s) > (e-s)/2) {
			cout << best << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}