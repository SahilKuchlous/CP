#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int perm[n];
	for (int i=0; i<n; i++) {
		cin >> perm[i];
		perm[i]--;
	}
	int init[n];
	for (int i=0; i<n; i++) {
		int val = i-perm[i];
		if (abs(val) > abs(val-n)) val -= n;
		if (abs(val) >= abs(val+n)) val += n; 
		init[i] = val;
	}
	sort(init, init+n);
	deque<int> dq;
	for (int i=0; i<n; i++) {
		dq.push_back(init[i]);
	}
	int o = max(abs(dq.front()), abs(dq.back()));
	for (int m=1; m<n; m++) {
		while (true) {
			if (abs(dq.front()-m) >= abs(dq.front()-m+n)) {
				dq.push_back(abs(dq.front()+n));
				dq.pop_front();
			} else {
				break;
			}
		}
		o = min(o, max(m-dq.front(), dq.back()-m));
	}
	reverse(perm, perm+n);
	for (int i=0; i<n; i++) {
		int val = i-perm[i];
		if (abs(val) > abs(val-n)) val -= n;
		if (abs(val) >= abs(val+n)) val += n; 
		init[i] = val;
	}
	sort(init, init+n);
	dq.clear();
	for (int i=0; i<n; i++) {
		dq.push_back(init[i]);
	}
	o = min(o, max(abs(dq.front()), abs(dq.back())));
	for (int m=1; m<n; m++) {
		while (true) {
			if (abs(dq.front()-m) >= abs(dq.front()-m+n)) {
				dq.push_back(abs(dq.front()+n));
				dq.pop_front();
			} else {
				break;
			}
		}
		o = min(o, max(m-dq.front(), dq.back()-m));
	}
	cout << o << endl;
}