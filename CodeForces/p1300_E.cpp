#include <iostream>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout << setprecision(9);
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector< pair<int, int> > groups;
	pair<int, int> cur = make_pair(a[0], 1);
	for (int i=1; i<n; i++) {
		if (a[i] == a[i-1]) {
			cur.second++;
		} else {
			groups.push_back(cur);
			cur = make_pair(a[i], 1);
		}
	}
	groups.push_back(cur);
	stack< pair<double, int> > ans;
	pair<double, int> p1, p2;
	for (int i=0; i<groups.size(); i++) {
		p1 = groups[i];
		if (ans.size() >= 1) p2 = ans.top();
		while (ans.size() >= 1) {
			if (p1.first <= p2.first) {
				ans.pop();
				p1 = make_pair((p1.first*p1.second+p2.first*p2.second)/(p1.second+p2.second), p1.second+p2.second);
				if (ans.size() == 0) {
					break;
				}
				p2 = ans.top();
			} else {
				break;
			}
		}
		ans.push(p1);
	}
	vector< pair<double, int> > o;
	while (ans.size() > 0) {
		o.push_back(ans.top());
		ans.pop();
	}
	reverse(o.begin(), o.end());
	for (auto i: o) {
		for (int j=0; j<i.second; j++) {
			cout << i.first << '\n';
		}
	}
}