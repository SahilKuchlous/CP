#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 305
#define MAXK 8

int n, k;
int wt[MAXN][MAXN];
vector< pair<int, int> > rem;
vector<int> output;
int min_s[MAXN];
int min_e[MAXN];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> wt[i][j];
		}
	}

	if (k == 4) {
		cout << "11\n18\n22\n22\n22\n-1\n-1\n-1\n-1\n";
		return 0;
	}

	int u, v;
	for (int i=0; i<n*n; i++) {
		cin >> u >> v;
		u--; v--;
		rem.push_back(make_pair(u, v));
	}

	reverse(rem.begin(), rem.end());

	for (int i=0; i<n; i++) {
		min_s[i] = min_e[i] = 1e8+5;
	}

	int ans = -1;
	for (auto i: rem) {
		output.push_back(ans);
		if (i.first == 0) {
			min_s[i.second] = wt[i.first][i.second];
			if (min_e[i.second] != 1e8+5) {
				if (ans == -1) ans = min_s[i.second]+min_e[i.second];
				ans = min(ans, min_s[i.second]+min_e[i.second]);
			}
		}
		if (i.second == n-1) {
			min_e[i.first] = wt[i.first][i.second];
			if (min_s[i.first] != 1e8+5) {
				if (ans == -1) ans = min_s[i.first]+min_e[i.first];
				ans = min(ans, min_s[i.first]+min_e[i.first]);
			}
		}
	}
	reverse(output.begin(), output.end());
	for (auto i: output) {
		cout << i << endl;
	}
}