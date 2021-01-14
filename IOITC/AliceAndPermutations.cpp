#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[10][10];
vector<int> cur;
int calc () {
	vector<int> a = cur;
	int o = 0;
	bool e;
	for (int i=0; i<10; i++) {
		e = false;
		for (int j=0; j<a.size()-1; j++) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				e = true;
			}
		}
		if (e) {
			o++;
		} else {
			return o;
		}
	}
	return 10;
}
int main () {
	for (int i=0; i<10; i++) {
		cur.clear();
		for (int j=0; j<=i; j++) {
			cur.push_back(j);
		}
		do {
			int cnt = calc();
			for (int j=cnt; j<10; j++) {
				dp[i][j]++;
			}
		} while (next_permutation(cur.begin(), cur.end()));
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << dp[n-1][k] << endl;
	}
}