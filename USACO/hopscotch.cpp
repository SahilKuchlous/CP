#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
ifstream fin("hopscotch.in");
ofstream fout("hopscotch.out");
const int MOD = 1000000007;
int grid[750][750];
vector<int> col_pos[750*750];
int sizes[750*750+1];
vector<long long> segtrees[750*750+1];
void update (int tree_i, int pos, int val) {
	while (pos < sizes[tree_i]) {
		segtrees[tree_i][pos] += val;
		segtrees[tree_i][pos] %= MOD;
		pos += pos & -pos;
	}
}
long long query (int tree_i, int pos) {
	int ret = 0;
	while (pos > 0) {
		ret += segtrees[tree_i][pos];
		ret %= MOD;
		pos -= pos & -pos;
	}
	return ret;
}
int main () {
	int r, c, k;
	fin >> r >> c >> k;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			fin >> grid[i][j];
			grid[i][j]--;
			col_pos[grid[i][j]].push_back(j);
		}
	}
	sizes[0] = c;
	for (int i=0; i<k; i++) {
		col_pos[i].push_back(-1);
		col_pos[i].push_back(c+1);
		sort(col_pos[i].begin(), col_pos[i].end());
		col_pos[i].resize(unique(col_pos[i].begin(), col_pos[i].end())-col_pos[i].begin());
		sizes[i+1] = col_pos[i].size();
	}
	for (int i=0; i<k+1; i++) {
		segtrees[i].resize(2*sizes[i], 0);
	}
	update(0, 1, 1);
	update(grid[0][0]+1, 1, 1);
	int pos;
	long long val;
	for (int i=1; i<r-1; i++) {
		for (int j=c-2; j>0; j--) {
			pos = lower_bound(col_pos[grid[i][j]].begin(), col_pos[grid[i][j]].end(), j)-col_pos[grid[i][j]].begin();
			val = query(0, j)-query(grid[i][j]+1, pos-1);
			if (val < 0) val += MOD;
			update(0, j+1, val);
			update(grid[i][j]+1, pos, val);
		}
	}
	pos = lower_bound(col_pos[grid[r-1][c-1]].begin(), col_pos[grid[r-1][c-1]].end(), c-1)-col_pos[grid[r-1][c-1]].begin();
	val = query(0, c-1)-query(grid[r-1][c-1]+1, pos-1);
	if (val < 0) val += MOD;
	fout << val << endl;
}