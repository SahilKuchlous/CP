#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n;
int a[1000100];
int l[1000100], r[1000100];
stack<int> cur;
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cur.push(1e9+1);
	for (int i=0; i<n; i++) {
		while (cur.top() < a[i]) cur.pop();
		l[i] = cur.top();
		cur.push(a[i]);
	}
	while (cur.size() > 1) cur.pop();
	for (int i=n-1; i>=0; i--) {
		while (cur.top() <= a[i]) cur.pop();
		r[i] = cur.top();
		cur.push(a[i]);
	}
	for (int i=0; i<n; i++) {
		if (l[i] == 1e9+1 && r[i] == 1e9+1) continue;
		o += min(l[i], r[i]);
	}
	cout << o << endl;
}
