#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("deleg.in");
ofstream fout("deleg.out");
int n;
set<int> adj[100100];
int far1, dist1 = 0, far2, dist2 = 0;
void dfs (int x, int p, int d, int t) {
	if (t == 0) {
		if (d > dist1) {
			dist1 = d;
			far1 = x;
		}
	} else {
		if (d > dist2) {
			dist2 = d;
			far2 = x;
		}
	}
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x, d+1, t);
		}
	}
}
int check (int x, int p, int l) {
	int r;
	multiset<int> cur;
	for (auto i: adj[x]) {
		if (i != p) {
			r = check(i, x, l);
			if (r == -1) {
				return -1;
			}
			r++;
			// cout << x << " " << r << endl;
			if (r < l) {
				if (cur.find(l-r) == cur.end()) {
					cur.insert(r);
				} else {
					cur.erase(cur.find(l-r));
				}
			}
		}
	}
	if (cur.size() > 1) return -1;
	if (cur.size() == 0) return 0;
	return *cur.begin();
}
int main () {
	ios_base::sync_with_stdio(false);
	fin.tie(0);
	fin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	dfs(1, 1, 0, 0);
	dfs(far1, far1, 0, 1);
	for (int i=1; i<=n-1; i++) {
		if ((n-1)%i == 0 && i<=dist2) {
			if (check(1, 1, i) == 0) {
				fout << '1';
			} else {
				fout << '0';
			}
		} else {
			fout << '0';
		}
	}
	fout << endl;
	// cout << check(1, 1, 4) << endl;
}