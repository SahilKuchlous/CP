#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string a, b;
int n;
vector< stack<char> > v;
void rec (int ai, int bi, stack<char> s, stack<char> x) {
	if (bi == n) {
		v.push_back(x);
		return;
	}
	if (ai < n) {
		s.push(a[ai]);
		x.push('i');
		ai++;
		rec(ai, bi, s, x);
		ai--;
		x.pop();
		s.pop();
	}
	if (s.size() > 0 && b[bi] == s.top()) {
		s.pop();
		x.push('o');
		bi++;
		rec(ai, bi, s, x);
		bi--;
		x.pop();
		s.push(b[bi]);
	}
}
int main () {
	while (cin >> a >> b) {
		v.clear();
		if (a.length() != b.length()) {
			cout << "[" << endl;
			cout << "]" << endl;
			continue;
		}
		n = a.length();
		stack<char> s;
		stack<char> x;
		rec(0, 0, s, x);
		char a[n*2];
		cout << "[" << endl;
		for (int i=0; i<v.size(); i++) {
			while (v[i].size()>0) {
				a[v[i].size()-1] = v[i].top();
				v[i].pop();
			}
			for (int j=0; j<2*n-1; j++) {
				cout << a[j] << " ";
			}
			cout << a[2*n-1] << endl;
		}
		cout << "]" << endl;
	}
}