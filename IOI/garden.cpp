#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
int c, k;
int grid[250][250];
int presum[250][250];
vector<int> starts[250];
vector<int> fins[250];
int o = 1e8;
int sum (int x1, int y1, int x2, int y2) {
	int o = presum[x2][y2];
	if (x1 > 0) o -= presum[x1-1][y2];
	if (y1 > 0) o -= presum[x2][y1-1];
	if (x1 > 0 && y1 > 0) o += presum[x1-1][y1-1];
	return o;
}
int main () {
	cin >> n >> m;
	cin >> c >> k;
	int ai, bi;
	for (int i=0; i<c; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		grid[ai][bi]++;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			presum[i][j] = grid[i][j];
			if (i > 0) presum[i][j] += presum[i-1][j];
			if (j > 0) presum[i][j] += presum[i][j-1];
			if (i > 0 && j > 0) presum[i][j] -= presum[i-1][j-1];
		}
	}
	multiset<int> p1, p2;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int l = 0, r = -1, cur = 0;
			while (true) {
				if (cur < k) {
					if (r == m-1) break;
					r++;
					cur += sum(i, r, j, r);
				} else {
					if (cur == k) {
						starts[l].push_back(2*(j-i+1)+2*(r-l+1));
						fins[r].push_back(2*(j-i+1)+2*(r-l+1));
						p2.insert(2*(j-i+1)+2*(r-l+1));
					}
					cur -= sum(i, l, j, l);
					l++;
				}
			}
		}
	}
	for (int i=0; i<m; i++) {
		for (auto j: fins[i]) {
			p1.insert(j);
		}
		for (auto j: starts[i]) {
			p2.erase(p2.find(j));
		}
		if (p1.size() == 0 || p2.size() == 0) continue;
		o = min(o, *p1.begin()+*p2.begin());
	}
	p1.clear();
	p2.clear();
	for (int i=0; i<m; i++) {
		starts[i].clear();
		fins[i].clear();
	}
	for (int i=0; i<m; i++) {
		for (int j=i; j<m; j++) {
			int l = 0, r = -1, cur = 0;
			while (true) {
				if (cur < k) {
					if (r == n-1) break;
					r++;
					cur += sum(r, i, r, j);
				} else {
					if (cur == k) {
						starts[l].push_back(2*(j-i+1)+2*(r-l+1));
						fins[r].push_back(2*(j-i+1)+2*(r-l+1));
						p2.insert(2*(j-i+1)+2*(r-l+1));
					}
					cur -= sum(l, i, l, j);
					l++;
				}
			}
		
		}
	}
	for (int i=0; i<n; i++) {
		for (auto j: fins[i]) {
			p1.insert(j);
		}
		for (auto j: starts[i]) {
			p2.erase(p2.find(j));
		}
		if (p1.size() == 0 || p2.size() == 0) continue;
		o = min(o, *p1.begin()+*p2.begin());
	}
	if (o < 1e8) {
		cout << o << endl;
	} else {
		cout << "NO" << endl;
	}
}