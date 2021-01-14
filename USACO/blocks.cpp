#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("blocks.in");
ofstream fout("blocks.out");
int main () {
	int n;
	fin >> n;
	int o[26];
	for (int i=0; i<26; i++) {
		o[i] = 0;
	}
	string s1, s2;
	map<char, int> m1;
	map<char, int> m2;
	set<char> s;
	int x = 0;
	for (int i=0; i<n; i++) {
		m1.clear();
		m2.clear();
		s.clear();
		fin >> s1 >> s2;
		for (auto c: s1) {
			s.insert(c);
			m1[c]++;
		}
		for (auto c: s2) {
			s.insert(c);
			m2[c]++;
		}
		for (auto c: s) {
			o[c-'a'] += max(m1[c], m2[c]);
		}
	}
	for (int i=0; i<26; i++) {
		fout << o[i] << endl;
	}
}