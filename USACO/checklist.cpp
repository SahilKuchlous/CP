#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream fin("checklist.in");
ofstream fout("checklist.out");

int dist (pair<int, int> a, pair<int, int> b) {
	return pow(a.first-b.first, 2) + pow(a.second-b.second, 2);
}

int main () {
	int h, g;
	fin >> h >> g;
	vector< pair<int, int> > a, b;
	a.push_back(make_pair(0, 0));
	b.push_back(make_pair(0, 0));
	int x, y;
	for (int i=0; i<h; i++) {
		fin >> x >> y;
		a.push_back(make_pair(x, y));
	}
	for (int i=0; i<g; i++) {
		fin >> x >> y;
		b.push_back(make_pair(x, y));
	}
	long long dp1[h+1][g+1];
	long long dp2[h+1][g+1];
	for (int i=0; i<=h; i++) {
		dp2[i][0] = 1e10;
	}
	for (int i=0; i<=g; i++) {
		dp1[0][i] = 1e10;
		dp2[0][i] = 1e10;
	}
	dp1[1][0] = 0;
	for (int i=2; i<=h; i++) {
		dp1[i][0] = dp1[i-1][0]+dist(a[i-1], a[i]);
	}
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=g; j++) {
			dp1[i][j] = min(dp1[i-1][j]+dist(a[i-1], a[i]), dp2[i-1][j]+dist(b[j], a[i]));
			dp2[i][j] = min(dp1[i][j-1]+dist(a[i], b[j]), dp2[i][j-1]+dist(b[j-1], b[j]));
		}
	}
	fout << dp1[h][g] << endl;
}