#include <iostream>
#include <map>
using namespace std;
int main () {
	while (true) {
		int s, b;
		cin >> s >> b;
		if (s == 0 && b == 0) {
			break;
		}
		map< int, pair<int, int> > m;
		if (s == 1) {
			m[1] = make_pair(-1, -1);
		} else {
			m[s] = make_pair(s-1, -1);
			m[1] = make_pair(-1, 2);
			for (int i=2; i<s; i++) {
				m[i] = make_pair(i-1, i+1);
			}
		}
		int l, r;
		for (int i=0; i<b; i++) {
			cin >> l >> r;
			if (m[l].first == -1 && m[r].second == -1) {
				cout << "* *" << endl;
			} else if (m[l].first == -1) {
				cout << "* " << m[r].second << endl;
				m[m[r].second].first = -1;
			} else if (m[r].second == -1) {
				cout << m[l].first << " *" << endl;
				m[m[l].first].second = -1;
			} else {
				cout << m[l].first << " " << m[r].second << endl;
				m[m[l].first].second = m[r].second;
				m[m[r].second].first = m[l].first;
			}
		}
		cout << "-" << endl;
	}
}