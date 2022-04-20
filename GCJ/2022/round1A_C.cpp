#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cout << "Case #" << test+1 << ": ";
		int e, w;
		cin >> e >> w;
		int cnt[e][w];
		for (int i=0; i<e; i++) {
			for (int j=0; j<w; j++) {
				cin >> cnt[i][j];
			}
		}
		map< vector<int>, int > prev, cur;
		for (int i=0; i<e; i++) {
			vector<int> perm;
			for (int j=0; j<w; j++) {
				for (int k=0; k<cnt[i][j]; k++) {
					perm.push_back(j);
				}
			}
			do {
				if (i == 0) {
					cur[perm] = perm.size();
					continue;
				}
				cur[perm] = 100000000;
				for (auto j: prev) {
					int cost = 0;
					for (int k=0; k<min(perm.size(), j.first.size()); k++) {
						if (j.first[k] != perm[k]) {
							break;
						}
						cost++;
					}
					cost = j.first.size()+perm.size()-2*cost;
					cur[perm] = min(cur[perm], j.second+cost);
				}
				/*
				for (auto i: perm) {
					cout << i << " ";
				}
				cout << endl;
				cout << cur[perm] << endl;
				*/
			} while (next_permutation(perm.begin(), perm.end()));
			prev = cur;
			cur.clear();
		}
		int o = 100000000;
		for (auto i: prev) {
			o = min(o, i.second+(int)i.first.size());
		}
		cout << o << '\n';
	}
}