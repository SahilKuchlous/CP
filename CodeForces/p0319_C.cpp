#include <iostream>
#include <deque>
using namespace std;
struct line {
	long long m, c;
	long long eval (long long x) {
		return m*x + c;
	}
	long double x_int (line l) {
		return (long double) (c-l.c)/(l.m-m);
	}
};
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[n];
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	deque<line> dq;
	dq.push_front({b[0], 0});
	long long o = 0;
	for (int i=1; i<n; i++) {
		while (dq.size() >= 2 && dq.back().eval(a[i]) >= dq[dq.size()-2].eval(a[i])) {
			dq.pop_back();
		}
		long long val = dq.back().eval(a[i]);
		o = val;
		line cur = {b[i], val};
		while (dq.size() >= 2 && cur.x_int(dq[0]) <= cur.x_int(dq[1])) {
			dq.pop_front();
		}
		dq.push_front(cur);
	}
	cout << o << endl;
}