#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
ifstream fin("fairphoto.in");
ofstream fout("fairphoto.out");
int main () {
	int n;
	fin >> n;
	pair<int, char> cows[n];
	int xi;
	char ti;
	for (int i=0; i<n; i++) {
		fin >> xi >> ti;
		cows[i] = make_pair(xi, ti);
	}
	sort(cows, cows+n);
	map<int, int> m1;
	map<int, int> m2;
	int cur = 0;
	int t;
	if (cows[0].second == 'W') {
		t = -1;
	} else {
		t = 1;
	}
	int o = 0;
	for (int i=0; i<n; i++) {
		if (cows[i].second == 'W') {
			cur++;
		} else {
			cur--;
		}
		if (i%2 == 0) {
			if (m1.find(cur) == m1.end()) m1[cur] = cows[i].first;
			if (cur+t >= 0) {
				o = max(o, cows[i].first-cows[1].first);
			} else {
				if (m2.find(cur-1) != m2.end()) o = max(o, cows[i].first-m2[cur-1]);
			}
		} else {
			if (m2.find(cur) == m2.end()) m2[cur] = cows[i].first;
			if (cur >= 0) {
				o = max(o, cows[i].first-cows[0].first);
			} else {
				if (m1.find(cur-1) != m1.end()) o = max(o, cows[i].first-m1[cur-1]);
			}
		}
	}
	fout << o << endl;
}