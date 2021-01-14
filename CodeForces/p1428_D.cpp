#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int h = 0;
	queue<int> q2, q3;
	vector< pair<int, int> > o;
	for (int i=0; i<n; i++) {
		if (a[i] == 0) continue;
		if (a[i] == 1) {
			if (q2.size() > 0) {
				o.push_back(make_pair(q2.front(), i));
				q2.pop();
			} else {
				o.push_back(make_pair(h, i));
				h++;
				if (q3.size() > 0) {
					o.push_back(make_pair(q3.front(), i));
					q3.pop();
				}
			}
			continue;
		}
		if (a[i] == 2) {
			if (q3.size() > 0) {
				o.push_back(make_pair(q3.front(), i));
				q3.pop();
			}
			o.push_back(make_pair(h, i));
			q2.push(h);
			h++;
			continue;
		}
		if (a[i] == 3) {
			if (q3.size() > 0) {
				o.push_back(make_pair(q3.front(), i));
				q3.pop();
			}
			o.push_back(make_pair(h, i));
			q3.push(h);
			h++;
			continue;
		}
	}
	if (q2.size() > 0 || q3.size() > 0) {
		cout << -1 << endl;
	} else {
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i.first+1 << " " << i.second+1 << endl;
		}
	}
}