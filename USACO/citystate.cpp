#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
ifstream fin("citystate.in");
ofstream fout("citystate.out");
int main () {
	int n;
	fin >> n;
	map< pair<string, string>, int> m;
	string s1, s2;
	for (int i=0; i<n; i++) {
		fin >> s1 >> s2;
		m[make_pair(s1.substr(0, 2), s2)]++;
	}
	long long o = 0;
	for (auto i: m) {
		if (i.first.first != i.first.second) {
			o += m[make_pair(i.first.second, i.first.first)]*i.second;
		}
	}
	fout << o/2 << endl;
}