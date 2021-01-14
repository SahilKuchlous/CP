#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n, m, w, b;
	cin >> n >> m >> w >> b;
	vector< pair<int, char> > a[n+1 ];
	int x, y;
	for (int i=0; i<w; i++) {
		cin >> x >> y;
		a[x].push_back(make_pair(y, 'W'));
	}
	for (int i=0; i<b; i++) {
		cin >> x >> y;
		a[x].push_back(make_pair(y, 'B'));
	}
	for (int i=1; i<=n; i++) {
		sort(a[i].begin(), a[i].end());
		/*
		for (auto j: a[i]) {
			cout << "(" << j.first << ", " << j.second << ") ";
		}
		cout << endl;
		*/
	}
	int e, p;
	long long int o = 0;
	for (int i=1; i<=n; i++) {
		e = 0;
		p = -1;
		for (auto j: a[i]) {
			if (j.second == 'B') {
				o += ((j.first-e)*(j.first-e+1))/2-1;
				if (p != -1) {
					o -= j.first-p+1;
				}
				p = -1;
				e = j.first;
			} else {
				if (p != -1) {
					o += ((j.first-e)*(j.first-e+1))/2 - ((j.first-p+1)*(j.first-p+2))/2;
					e = p;
				}
				p = j.first;
			}
			//cout << o << endl;
		}
		o += ((m-e)*(m-e+1))/2;
		if (p != -1) {
			o -= w-p;
		}
		//cout << "F: " << o << endl;
	}
	cout << o << endl;
}