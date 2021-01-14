#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, p;
int a[500001];
vector<int> pos[100001];
set<int> ord;
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> p;
	for (int i=0; i<p; i++) {
		cin >> a[i];
		a[i]--;
		pos[a[i]].push_back(i);
	}
	for (int i=0; i<n; i++) {
		reverse(pos[i].begin(), pos[i].end());
	}
	for (int i=0; i<p; i++) {
		if (ord.find(i) != ord.end()) {
			ord.erase(i);
		} else {
			o++;
			if (ord.size() == k) {
				ord.erase(prev(ord.end()));
			}
		}
		pos[a[i]].pop_back();
		ord.insert(pos[a[i]].size() == 0 ? (int)1e7 : pos[a[i]].back());
	}
	cout << o << endl;
}