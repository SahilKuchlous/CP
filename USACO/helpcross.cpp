#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("helpcross.in");
ofstream fout("helpcross.out");
int main () {
	int c, n;
	fin >> c >> n;
	int ckn[c];
	for (int i=0; i<c; i++) {
		fin >> ckn[i];
	}
	pair<int, int> cow[n];
	for (int i=0; i<n; i++) {
		fin >> cow[i].first >> cow[i].second;
	}
	sort(ckn, ckn+c);
	sort(cow, cow+n);
	set< pair<int, int> > opts;
	int ind = 0;
	int o = 0;
	for (int i=0; i<c; i++) {
		while (ind < n && cow[ind].first <= ckn[i]) {
			opts.insert(make_pair(cow[ind].second, ind));
			ind++;
		}
		while (opts.size() > 0) {
			if ((*opts.begin()).first < ckn[i]) {
				opts.erase(opts.begin());
			} else {
				o++;
				opts.erase(opts.begin());
				break;
			}
		}
	}
	fout << o << endl;
}