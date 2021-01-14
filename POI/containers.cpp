#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, k;
int val[200100];
vector< pair<int, int> > delta[200100];
int cur[400][400];
int main () {
	cin >> n >> k;
	int sq = sqrt(n);
	int ai, li, di;
	for (int i=0; i<k; i++) {
		cin >> ai >> li >> di;
		ai--;
		if (di >= sq) {
			for (int j=ai; j<ai+li*di; j+=di) val[j]++;
		} else {
			delta[ai].push_back(make_pair(1, di));
			if (ai+li*di < n) delta[ai+li*di].push_back(make_pair(-1, di));
		}
	}
	for (int i=0; i<n; i++) {
		for (auto j: delta[i]) {
			cur[j.second][i%j.second] += j.first;
		}
		for (int j=1; j<=sq; j++) {
			val[i] += cur[j][i%j];
		}
	}
	for (int i=0; i<n; i++) {
		cout << val[i] << " ";
	}
	cout << endl;
}