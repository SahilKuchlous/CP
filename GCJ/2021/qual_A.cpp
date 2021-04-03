#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve () {
	int n;
	cin >> n;
	vector<int> v;
	int inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	int o = 0;
	vector<int> nxt;
	for (int i=0; i<n-1; i++) {
		int min_i = -1, min_v = n+1;
		for (int j=0; j<v.size(); j++) {
			if (v[j] < min_v) {
				min_v = v[j];
				min_i = j;
			}
		}
		o += min_i+1;
		for (int j=min_i-1; j>=0; j--) {
			nxt.push_back(v[j]);
		}
		for (int j=min_i+1; j<v.size(); j++) {
			nxt.push_back(v[j]);
		}
		v = nxt;
		nxt.clear();
	}
	return o;
}
int main () {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
}