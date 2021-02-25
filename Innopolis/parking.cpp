#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100005
string zones;
string seq;
int n, m;
vector<int> gaps;
int psum[MAXN][2];
void init () {
	gaps.clear();
	psum[0][0] = psum[0][1] = 0;
} 
bool check (int x) {
	if (x == -1) return true;
	priority_queue<int> odd, even;
	for (auto i: gaps) {
		if (i%2 == 1 && i > 1) {
			odd.push(i);
		} else {
			even.push(i);
		}
	}
	int cur;
	for (int i=0; i<psum[x][1]; i++) {
		if (odd.size() > 0) {
			cur = odd.top()-3;
			odd.pop();
			if (cur <= 0) continue;
			even.push(cur);
		} else if (even.size() > 0) {
			cur = even.top()-3;
			even.pop();
			if (cur <= 0) continue;
			odd.push(cur);
		}
	}
	for (int i=0; i<psum[x][0]; i++) {
		if (odd.size() > 0) {
			cur = odd.top()-2;
			odd.pop();
			if (cur <= 0) continue;
			odd.push(cur);
		} else if (even.size() > 0) {
			cur = even.top()-2;
			even.pop();
			if (cur <= 0) continue;
			even.push(cur);
		}
	}
	return (odd.size() > 0 || even.size() > 0);
}
void solve () {
	cin >> zones;
	cin >> seq;
	n = zones.length();
	m = seq.length();
	init();
	int prv = -1;
	for (int i=0; i<n; i++) {
		if (zones[i] == '.') continue;
		if (i-prv-2 > 0) gaps.push_back(i-prv-2);
		prv = i;
	}
	if (n-prv-2 > 0) gaps.push_back(n-prv-2);
	for (int i=1; i<=n; i++) {
		psum[i][0] = psum[i-1][0] + (seq[i-1] == 'M');
		psum[i][1] = psum[i-1][1] + (seq[i-1] == 'C');
	}
	int l = -1, r = m, mid, o;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			o = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	for (int i=0; i<=o; i++) {
		cout << "Y";
	}
	for (int i=o+1; i<=m; i++) {
		cout << "N";
	}
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}