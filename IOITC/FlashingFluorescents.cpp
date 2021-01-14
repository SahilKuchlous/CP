#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n;
map< pair< vector<bool>, set<int> >, int > memo;
int solve (vector<bool> a, set<int> c) {
	if (memo.find(make_pair(a, c)) != memo.end()) {
		return memo[make_pair(a, c)];
	}
	for (auto i: c) {
		a[i] = !a[i];
	}
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	bool d = true;
	for (int i=0; i<n; i++) {
		if (!a[i]) {
			d = false;
		}
	}
	if (d) {
		cout << "E" << endl;
		return 0;
	}
	set<int> nc;
	for (auto i: c) {
		if (i+1 < n) {
			nc.insert(i+1);
		}
	}
	int m = 100000;
	if (nc.size() > 0) {
		m = solve(a, nc);
	}
	int x;
	for (int i=0; i<n; i++) {
		if (!a[i] && c.find(i) == c.end()) {
			nc.insert(i);
			x = solve(a, nc);
			memo[make_pair(a, nc)] = x;
			nc.erase(i);
			if (x < m) {
				m = x;
			}
		}
	}
	return m+1;
}
int main () {
	string s;
	cin >> s;
	n = s.length();
	vector<bool> a; 
	for (auto x: s) {
		if (x == '0') {
			a.push_back(false);
		} else {
			a.push_back(true);
		}
	}
	set<int> c;
	cout << solve(a, c) << endl;
}