#include <fstream>
#include <iostream>
#include <string>
#include <set>
using namespace std;
ifstream fin("whereami.in");
ofstream fout("whereami.out");
int main () {
	int n;
	fin >> n;
	string s;
	fin >> s;
	set<string> m;
	int o;
	for (int i=1; i<n; i++) {
		m.clear();
		for (int j=0; j<n-i+1; j++) {
			m.insert(s.substr(j, i));
		}
		if (m.size() == n-i+1) {
			o = i;
			break;
		}
	}
	fout << o << endl;
}