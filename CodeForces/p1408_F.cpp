#include <iostream>
#include <vector>
using namespace std;
vector< pair<int, int> > o;
void solve (int l, int r) {
	if (l == r) return;
	int m = (l+r)/2;
	solve(l, m);
	solve(m+1, r);
	for (int i=l; i<=m; i++) {
		o.push_back(make_pair(i, m+i-l+1));
	}
}
int main () {
	int n;
	cin >> n;
	int pow = 1;
	while (2*pow < n) pow *= 2;
	solve(1, pow);
	solve(n-pow+1, n);
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i.first << " " << i.second << endl;
	}
}