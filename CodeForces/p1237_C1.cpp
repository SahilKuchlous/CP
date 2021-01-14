#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
bool sort_func (const vector<int> lhs, const vector<int> rhs) {
	if (lhs[0] != rhs[0]) {
		return lhs[0] < rhs[0];
	} else if (lhs[1] != rhs[1]) {
		return lhs[1] < rhs[1];
	} else if (lhs[2] != rhs[2]) {
		return lhs[2] < rhs[2];
	} else {
		return lhs[3] < rhs[3];
	}
}
int main () {
	int n;
	cin >> n;
	vector<int> v[n];
	int x, y, z;
	for (int i=0; i<n; i++) {
		cin >> x >> y >> z;
		v[i].push_back(x);
		v[i].push_back(y);
		v[i].push_back(z);
		v[i].push_back(i+1);
	}
	sort(v, v+n, sort_func);
	for (int i=0; i<n; i+=2) {
		cout << v[i][3] << " " << v[i+1][3] << endl;
	}
}
*/
int main () {
	int n;
	cin >> n;
	int a[n][3];
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> a[i][j];
		}
	}
	bool f[n];
	for (int i=0; i<n; i++) {
		f[i] = false;
	}
	int c = 0;
	for (int i=0; i<n; i++) {
		if (f[i]) {
			continue;
		}
		double min_dist = 1000000000;
		int ind = -1;
		for (int j=i+1; j<n; j++) {
			if (f[j]) {
				continue;
			} else {
				if (abs(a[j][0]-a[i][0]) + abs(a[j][1]-a[i][1]) + abs(a[j][2]-a[i][2]) < min_dist) {
					min_dist = abs(a[j][0]-a[i][0]) + abs(a[j][1]-a[i][1]) + abs(a[j][2]-a[i][2]);
					ind = j;
				}
			}
		}
		f[i] = true;
		f[ind] = true;
		cout << i+1 << " " << ind+1 << endl;
	}
}