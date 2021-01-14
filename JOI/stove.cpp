#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
int n, k;
int t[MAXN];
vector<int> dif;
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> t[i];
	}
	for (int i=1; i<n; i++) {
		dif.push_back(t[i]-t[i-1]-1);
	}
	sort(dif.begin(), dif.end());
	k--;
	while (k--) {
		if (dif.back() > 0) o += dif.back();
		dif.pop_back();
	}
	o = t[n-1]-t[0]+1-o;
	cout << o << endl;
}