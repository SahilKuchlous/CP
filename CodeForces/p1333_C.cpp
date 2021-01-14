#include <iostream>
#include <map>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	map<long long, int> prev;
	prev[0] = -1;
	int old = -1;
	long long o = 0;
	long long s = 0;
	for (int i=0; i<n; i++) {
		s += a[i];
		if (prev.find(s) != prev.end()) {
			old = max(old, prev[s]+1);
		}
		o += i-old;
		prev[s] = i;
	}
	cout << o << endl;
}