#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
ifstream fin("lineup.in");
ofstream fout("lineup.out");
int main () {
	map<string, int> m = {{"Beatrice", 1}, {"Belinda", 2}, {"Bella", 3}, {"Bessie", 4}, {"Betsy", 5}, {"Blue", 6}, {"Buttercup", 7}, {"Sue", 8}};
	map<int, string> x = {{1, "Beatrice"}, {2, "Belinda"}, {3, "Bella"}, {4, "Bessie"}, {5, "Betsy"}, {6, "Blue"}, {7, "Buttercup"}, {8, "Sue"}};
	int n;
	fin >> n;
	string in;
	set< pair<int, int> > r;
	for (int i=0; i<n; i++) {
		string c1, w1, w2, w3, w4, c2;
		fin >> c1 >> w1 >> w2 >> w3 >> w4 >> c2;
		r.insert(make_pair(m[c1], m[c2]));
	}
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	bool p = true;
	while (true) {
		p = true;
		for (auto i: r) {
			if (abs(find(a, a+8, i.first)-find(a, a+8, i.second)) != 1) {
				p = false;
				break;
			}
		}
		if (p) {
			break;
		}
		next_permutation(a, a+8);
	}
	for (int i=0; i<8; i++) {
		fout << x[a[i]] << endl;
	}
}