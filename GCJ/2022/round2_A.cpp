#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cout << "Case #" << test+1 << ": ";
		int n, k;
		cin >> n >> k;
		vector< pair<int, int> > skips;
		long long rem = n*n-1-k;
		long long pos = n/2+1;
		long long skip = 8*(n/2)-2;
		int dir = 4;
		for (int i=0; i<n/2; i++) {
			// cout << "s: " << rem << endl;
			for (int j=0; j<dir; j++) {
				if (skip <= 1) break;
				if (rem >= skip) {
					rem -= skip;
					dir = 4-j;
					skips.push_back(make_pair(pos, pos+skip+1));
					pos += skip+1;
					skip -= 8;
					break;
				} else if (j == dir-1) {
					dir = 4;
					skip -= 2;
					pos += n-2*(i+1);
				} else {
					skip -= 2;
					pos += n-2*i-1;
				}
			}
			// cout << "e: " << rem << endl;
		}
		if (rem != 0) {
			cout << "IMPOSSIBLE" << '\n';
		} else {
			cout << skips.size() << '\n';
			for (auto i: skips) {
				cout << i.first << " " << i.second << '\n';
			}
		}
	}
}