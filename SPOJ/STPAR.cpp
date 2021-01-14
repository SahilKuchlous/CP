#include <iostream>
#include <stack>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n ==  0) {
			break;
		}
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int x = 1;
		stack<int> s;
		for (int i=0; i<n; i++) {
			while (true) {
				if (s.size() > 0 && s.top() == x) {
					s.pop();
					x++;
				} else {
					break;
				}
			}
			if (a[i] != x) {
				s.push(a[i]);
			} else {
				x++;
			}
		}
		while (true) {
			if (s.size() > 0 && s.top() == x) {
				s.pop();
				x++;
			} else {
				break;
			}
		}
		if (s.size() == 0) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}