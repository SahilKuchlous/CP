#include <iostream>
#include <deque>
using namespace std;
#define MAXN 200005
int n, k;
char s[MAXN];
int last[MAXN];
int temp[MAXN];
deque<int> dq;
int prv;
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		if (s[i] == 'I') last[i] = i;
	}
	for (int i=n-1; i>=0; i--) {
		if (s[i] != 'I') continue;
		dq.push_front(i);
		if (dq.size() > k) dq.pop_back();
		if (dq.size() == k) {
			temp[i] = last[dq.back()];
		} else {
			temp[i] = 1e8;
		}
	}
	for (int i=0; i<n; i++) last[i] = temp[i];
	prv = -1;
	for (int i=n-1; i>=0; i--) {
		if (s[i] == 'I') {
			prv = i;
			continue;
		}
		if (s[i] == 'O') {
			if (prv == -1) {
				temp[i] = 1e8;
			} else {
				temp[i] = last[prv];
			}
		}
	}
	for (int i=0; i<n; i++) last[i] = temp[i];
	dq.clear();
	for (int i=n-1; i>=0; i--) {
		if (s[i] != 'O') continue;
		dq.push_front(i);
		if (dq.size() > k) dq.pop_back();
		if (dq.size() == k) {
			temp[i] = last[dq.back()];
		} else {
			temp[i] = 1e8;
		}
	}
	for (int i=0; i<n; i++) last[i] = temp[i];
	prv = -1;
	for (int i=n-1; i>=0; i--) {
		if (s[i] == 'O') {
			prv = i;
			continue;
		}
		if (s[i] == 'J') {
			if (prv == -1) {
				temp[i] = 1e8;
			} else {
				temp[i] = last[prv];
			}
		}
	}
	for (int i=0; i<n; i++) last[i] = temp[i];
	dq.clear();
	for (int i=n-1; i>=0; i--) {
		if (s[i] != 'J') continue;
		dq.push_front(i);
		if (dq.size() > k) dq.pop_back();
		if (dq.size() == k) {
			temp[i] = last[dq.back()];
		} else {
			temp[i] = 1e8;
		}
	}
	for (int i=0; i<n; i++) last[i] = temp[i];
	int o = 1e8;
	for (int i=0; i<n; i++) {
		if (s[i] != 'J') continue;
		if (last[i] == 1e8) continue;
		o = min(o, last[i]-i+1-3*k);
	}
	cout << (o == 1e8 ? -1 : o) << endl;
}