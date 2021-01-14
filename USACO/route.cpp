#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("route.in");
ofstream fout("route.out");
int main () {
	int n, m, r;
	fin >> n >> m >> r;
	int lval[n];
	for (int i=0; i<n; i++) {
		fin >> lval[i];
	}
	int rval[m];
	for (int i=0; i<m; i++) {
		fin >> rval[i];
	}
	pair<int, int> paths[r];
	for (int i=0; i<r; i++) {
		fin >> paths[i].first >> paths[i].second;
		paths[i].first--;
		paths[i].second--;
	}
	sort(paths, paths+r);
	long long dp_l[n];
	for (int i=0; i<n; i++) {
		dp_l[i] = lval[i];
	}
	long long dp_r[m];
	for (int i=0; i<m; i++) {
		dp_r[i] = rval[i];
	}
	long long new_l, new_r;
	long long o = 0;
	for (auto i: paths) {
		new_l = max(dp_l[i.first], dp_r[i.second]+lval[i.first]);
		new_r = max(dp_r[i.second], dp_l[i.first]+rval[i.second]);
		dp_l[i.first] = new_l;
		dp_r[i.second] = new_r;
		o = max(o, dp_l[i.first]);
		o = max(o, dp_r[i.second]);
	}
	fout << o << endl;
}