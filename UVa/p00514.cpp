#include <iostream>
#include <stack>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		while (true) {
			int a[n];
			cin >> a[0];
			if (a[0] == 0) {
				break;
			}
			for (int i=1; i<n; i++) {
				cin >> a[i];
			}
			stack<int> s;
			int x = 0, l = 0;
			while (l <= n) {
				if (s.size() == 0 || s.top() != a[x]) {
					l++;
					s.push(l);
				} else {
					s.pop();
					x++;
				}
			}
			if (s.size() > 1) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		}
		cout << endl;
	}
}