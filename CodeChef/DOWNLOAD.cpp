#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main () {
	int n;
	cin >> n;
	int s, e;
	vector< pair<int, int> > v;
	for (int i=0; i<n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	sort(v.begin(), v.end());
	map< pair<int, int>, int > m;
	int c = 1;
	priority_queue < int, vector<int>, greater<int> > ends;
	int x = 1;
	int l = 0;
	if (v[0].first != 1) {
		m[make_pair(1, v[0].first-1)] = 0;
	}
	ends.push(v[0].second);
	l = v[0].first;
	while (true) {
		if (x == n) {
			break;
		}
		if (ends.size() == 0 || v[x].first <= ends.top()) {
			//cout << "a " << l << " " << v[x].first-1 << " " << x << endl;
			if (l != v[x].first) {
				m[make_pair(l, v[x].first-1)] = c;
			}
			l = v[x].first;
			ends.push(v[x].second);
			c++;
			x++;
		} else {
			//cout << "b " << l << " " << ends.top() << endl;
			m[make_pair(l, ends.top())] = c;
			l = ends.top()+1;
			ends.pop();
			c--;
		}
	}
	while (ends.size() > 0) {
		m[make_pair(l, ends.top())] = c;
		l = ends.top()+1;
		ends.pop();
		c--;
	}
	m[make_pair(l, 1000000001)] = 0;
	/*
	for (auto i: m) {
		cout << i.first.first << " " << i.first.second << ": " << i.second << endl;
	}
	*/
	vector< pair<int, int> > r;
	for (auto i: m) {
		r.push_back(i.first);
	}
	sort(r.begin(), r.end());
	int q;
	cin >> q;
	int k, a, o;
	vector< pair<int, int> >::iterator p;
	for (int i=0; i<q; i++) {
		cin >> k;
		o = 0;
		for (int j=0; j<k; j++) {
			cin >> a;
			p = upper_bound(r.begin(), r.end(), make_pair(a, 0));
			o += m[*p];
		}
		cout << o << endl;
	}
}