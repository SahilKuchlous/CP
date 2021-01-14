#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("partition.in");
ofstream fout("partition.out");
int n, k;
int presum[20][20];
vector<int> fences;
bool check (int rem, int val) {
	int cur = rem;
	int prev = 0;
	bool pos = true;
	int i = 1;
	while (i <= n) {
		int h = 0;
		for (int j=1; j<fences.size(); j++) {
			h = max(h, presum[i][fences[j]]-presum[prev][fences[j]]-presum[i][fences[j-1]]+presum[prev][fences[j-1]]);
		}
		if (h > val) {
			prev = i-1;
			cur--;
			if (cur < 0) {
				pos = false;
				break;
			}
		} else {
			i++;
		}
	}
	return pos;
}
int main () {
	fin >> n >> k;
	int grid[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			fin >> grid[i][j];
		}
	}
	for (int i=0; i<=n; i++) {
		presum[0][i] = presum[i][0] = 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			presum[i][j] = grid[i-1][j-1];
			if (i > 0) presum[i][j] += presum[i-1][j];
			if (j > 0) presum[i][j] += presum[i][j-1];
			if (i > 0 && j > 0) presum[i][j] -= presum[i-1][j-1];
		}
	}
	int total = presum[n][n];
	int o = total;
	for (int i=0; i < (1<<(n-1)); i++) {
		fences.clear();
		fences.push_back(0);
		for (int j=0; j<n-1; j++) {
			if (i & 1<<j) {
				fences.push_back(j+1);
			}
		}
		fences.push_back(n);
		int rem = k-fences.size()+2;
		if (rem < 0) continue;
		int l = 0, r = total, m, ans = total;
		while (l <= r) {
			m = (l+r)/2;
			if (check(rem, m)) {
				ans = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}
		o = min(o, ans);
	}
	fout << o << endl;
}