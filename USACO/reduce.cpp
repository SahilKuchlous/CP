#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
using namespace std;
ifstream fin("reduce.in");
ofstream fout("reduce.out");
bool sort_func (const pair<int, int> p1, const pair<int, int> p2) {
	return p1.second < p2.second;
}
int main () {
	int n;
	fin >> n;
	pair<int, int> points[n];
	for (int i=0; i<n; i++) {
		fin >> points[i].first >> points[i].second;
	}
	set< pair<int, int> > bound;
	if (n <= 4) {
		cout << 0 << endl;
		return 0;
	}
	sort(points, points+n);
	for (int i=0; i<min(10, n); i++) {
		bound.insert(points[i]);
		bound.insert(points[n-i-1]);
	}
	sort(points, points+n, sort_func);
	for (int i=0; i<min(10, n); i++) {
		bound.insert(points[i]);
		bound.insert(points[n-i-1]);
	}
	vector< pair<long long, long long> > v;
	for (auto i: bound) {
		v.push_back(i);
	}
	long long min_x, min_y, max_x, max_y;
	long long o = 1e10;
	for (int i1=0; i1<v.size(); i1++) {
		for (int i2=i1+1; i2<v.size(); i2++) {
			for (int i3=i2+1; i3<v.size(); i3++) {
				min_x = min_y = 100000;
				max_x = max_y = -1;
				for (int i=0; i<v.size(); i++) {
					if (i != i1 && i != i2 && i != i3) {
						min_x = min(min_x, v[i].first);
						max_x = max(max_x, v[i].first);
						min_y = min(min_y, v[i].second);
						max_y = max(max_y, v[i].second);
					}
				}
				o = min(o, (max_x-min_x)*(max_y-min_y));
			}
		}
	}
	fout << o << endl;
}