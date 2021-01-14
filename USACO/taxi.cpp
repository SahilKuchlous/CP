#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("taxi.in");
ofstream fout("taxi.out");
int main () {
	int n, m;
	fin >> n >> m;
	vector< pair<int, int> > s;
	s.push_back(make_pair(0, 1));
	s.push_back(make_pair(m, -1));
	long long o = 0;
	int si, ei;
	for (int i=0; i<n; i++) {
		fin >> si >> ei;
		s.push_back(make_pair(si, -1));
		s.push_back(make_pair(ei, 1));
		o += abs(si-ei);
	}
	sort(s.begin(), s.end());
	int psum = s[0].second;
	for (int i=1; i<s.size(); i++) {
		o += (s[i].first-s[i-1].first)*abs(psum);
		psum += s[i].second;
	}
	fout << o << endl;
}