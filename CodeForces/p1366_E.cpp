#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005
#define MOD 998244353
int n, m;
int a[MAXN];
int b[MAXN];
vector< pair<int, int> > ord;
vector< pair<int, int> > uni;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	for (int i=0; i<n; i++) {
		ord.push_back(make_pair(a[i], i));
	}
	sort(ord.begin(), ord.end());
	uni.push_back(ord[0]);
	for (auto i: ord) {
		if (uni.back().first == i.first) {
			uni.pop_back();
		}
		uni.push_back(i);
	}
	int bi = 1;
	long long o = 1;
	if (uni[0].first != b[0]) {
		cout << 0 << endl;
		return 0;
	}
	int prv = uni[0].second;
	for (int i=1; i<uni.size(); i++) {
		if (bi == m) break;
		if (uni[i].first < b[bi]) {
			prv = max(prv, uni[i].second);
			continue;
		}
		if (uni[i].first > b[bi]) {
			o = 0;
			break;
		}
		o = o*max(0, uni[i].second-prv) % MOD;
		prv = uni[i].second;
		bi++;
	}
	if (bi != m) {
		o = 0;
	}
	cout << o << endl;
}