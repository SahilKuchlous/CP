#include <iostream>
#include <stack>
#include <set>
using namespace std;
#define MAXN 100005
int n;
bool pos = true;
stack<int> s;
char type[2*MAXN];
int val[2*MAXN];
set<int> cur;
int main () {
	cin >> n;
	for (int i=0; i<2*n; i++) {
		cin >> type[i];
		if (type[i] == '-') cin >> val[i];
	}
	for (int i=0; i<2*n; i++) {
		if (type[i] == '+') {
			s.push(i);
		} else {
			if (s.size() == 0) {
				pos = false;
				break;
			}
			val[s.top()] = val[i];
			s.pop();
		}
	}
	for (int i=0; i<2*n; i++) {
		if (type[i] == '+') {
			cur.insert(val[i]);
		} else {
			if (*cur.begin() != val[i]) pos = false;
			cur.erase(val[i]);
		}
	}
	if (!pos) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i=0; i<2*n; i++) {
			if (type[i] == '+') cout << val[i] << " ";
		}
		cout << endl;
	}
}