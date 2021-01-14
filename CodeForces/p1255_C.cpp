#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	map< int, vector< vector<int> > > m;
	int a, b, c;
	for (int i=0; i<n-2; i++) {
		cin >> a >> b >> c;
		m[a].push_back({b, c});
		m[b].push_back({a, c});
		m[c].push_back({a, b});
	}
	int x = 0;
	for (int i=1; i<=n; i++) {
		if (m[i].size() == 1) {
			x = i;
			break;
		}
	}
	vector<int> o;
	o.push_back(x);
	vector<int> s = m[x][0];
	int px = x;
	int nx;
	if (m[s[0]].size() == 2) {
		x = s[0];
		nx = s[1];
	} else {
		x = s[1];
		nx = s[0];
	}
	o.push_back(x);
	o.push_back(nx);
	while (true) {
		for (auto i: m[x]) {
			if (i[0] == nx && i[1] != px) {
				px = x;
				x = nx;
				nx = i[1];
				break;
			} else if (i[1] == nx && i[0] != px) {
				px = x;
				x = nx;
				nx = i[0];
				break;
			}
		}
		o.push_back(nx);
		if (m[x].size() == 2) {
			break;
		}
	}
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}