#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int main () {
	string s;
	int x = 0;
	while (true) {
		x++;
		cin >> s;
		if (s == "end") {
			break;
		}
		vector< stack<char> > v;
		int m;
		int mi;
		for (auto i: s) {
			m = 100;
			mi = -1;
			for (int j=0; j<v.size(); j++) {
				if (v[j].top() >= i) {
					if (v[j].top()-i < m) {
						m = v[j].top()-i;
						mi = j;
					}
				}
			}
			if (mi == -1) {
				stack<char> s;
				s.push(i);
				v.push_back(s);
			} else {
				v[mi].push(i);
			}
		}
		/*
		for (auto i: v) {
			while (i.size() > 0) {
				cout << i.top() << " ";
				i.pop();
			}
			cout << endl;
		}
		*/
		cout << "Case " << x << ": " << v.size() << endl;
	}
}