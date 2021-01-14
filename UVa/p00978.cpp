#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, g, b;
		cin >> n >> g >> b;
		priority_queue<int> qg;
		priority_queue<int> qb;
		int x;
		for (int i=0; i<g; i++) {
			cin >> x;
			qg.push(x);
		}
		for (int i=0; i<b; i++) {
			cin >> x;
			qb.push(x);
		}
		vector<int> vg;
		vector<int> vb;
		while (qg.size() > 0 && qb.size() > 0) {
			vg.clear();
			vb.clear();
			for (int i=0; i<n; i++) {
				if (qg.size() == 0 || qb.size() == 0) {
					break;
				}
				if (qg.top() > qb.top()) {
					vg.push_back(qg.top() - qb.top());
				} else if (qg.top() < qb.top()) {
					vb.push_back(qb.top() - qg.top());
				}
				qg.pop();
				qb.pop();
			}
			for (int i=0; i<vg.size(); i++) {
				qg.push(vg[i]);
			}
			for (int i=0; i<vb.size(); i++) {
				qb.push(vb[i]);
			}
		}
		if (qg.size() > 0) {
			cout << "green wins" << endl;
			while (qg.size() > 0) {
				cout << qg.top() << endl;
				qg.pop();
			}
		} else if (qb.size() > 0) {
			cout << "blue wins" << endl;
			while (qb.size() > 0) {
				cout << qb.top() << endl;
				qb.pop();
			}
		} else {
			cout << "green and blue died" << endl;
		}
		if (t != 0) {
			cout << endl;
		}
	}
}