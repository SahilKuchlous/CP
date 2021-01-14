#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("haybales.in");
ofstream fout("haybales.out");
int main () {
	int n, q;
	fin >> n >> q;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		fin >> v[i];
	}
	sort(v.begin(), v.end());
	int l, r;
	for (int i=0; i<q; i++) {
		fin >> l >> r;
		fout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << endl;
	}
}