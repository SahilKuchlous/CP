#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
set<int> vis;
map<int, vector< vector<int> > > f;
int o;
int s;
void rec (int c) {
	if (vis.count(c) > 0) {
		return;
	}
	vis.insert(c);
	o += 1;
	for (auto i: f[c]) {
		if (i[1] <= s) {
			rec(i[0]);
		}
	}
}
int main () {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		vector<int> v;
		v.push_back(b);
		v.push_back(c);
		f[a].push_back(v);
		v.clear();
		v.push_back(a);
		v.push_back(c);
		f[b].push_back(v);
	}
	int k;
	cin >> k >> s;
	int c;
	o = 0;
	for (int i=0; i<k; i++) {
		cin >> c;
		c--;
		rec(c);
	}
	cout << o << endl;
}