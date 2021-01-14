#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("shufflegold.in");
ofstream fout("shufflegold.out");
int main () {
	int n, m, q;
	fin >> n >> m >> q;
	int shift[m+1];
	for (int i=1; i<=m; i++) {
		fin >> shift[i];
		shift[i]--;
	}
	vector<int> main_path;
	bool vis[m+1];
	for (int i=1; i<=m; i++) {
		vis[i] = false;
	}
	int cur = m;
	while (cur != 0) {
		main_path.push_back(cur);
		vis[cur] = true;
		cur = shift[cur];
	}
	reverse(main_path.begin(), main_path.end());
	int final[m+1];
	for (int i=0; i<main_path.size(); i++) {
		final[main_path[i]] = n-main_path.size()+i+1;
	}
	vector< vector<int> > cycles;
	vector<int> cur_cycle;
	for (int i=1; i<=m; i++) {
		if (!vis[i]) {
			cur = i;
			while (shift[cur] != i) {
				vis[cur] = true;
				cur_cycle.push_back(cur);
				cur = shift[cur];
			}
			vis[cur] = true;
			cur_cycle.push_back(cur);
			cycles.push_back(cur_cycle);
			cur_cycle.clear();
		}
	}
	for (auto cycle: cycles) {
		for (int i=0; i<cycle.size(); i++) {
			final[cycle[i]] = cycle[(i+n-m)%cycle.size()];
		}
	}
	int new_final[m+1];
	for (int i=1; i<=m; i++) {
		new_final[shift[i]+1] = final[i];
	}
	for (int i=1; i<=m; i++) {
		final[i] = new_final[i];
	}
	int pos;
	for (int i=0; i<q; i++) {
		fin >> pos;
		pos = n-pos+1;
		if (pos > n-m) {
			fout << final[m-n+pos] << " A" << endl;
		} else if (pos <= main_path.size()) {
			fout << main_path[pos-1] << " B" << endl;
		} else {
			fout << pos+m-main_path.size() << " C" << endl;
		}
	}
}