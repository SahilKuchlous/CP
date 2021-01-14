#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		map<int, int> pos;
		vector<int> min_v, max_v;
		for (int i=0; i<n/2; i++) {
			pos[a[i]+a[n-i-1]]++;
			min_v.push_back(-min(a[i], a[n-i-1]));
			max_v.push_back(max(a[i], a[n-i-1]));
		}
		sort(min_v.begin(), min_v.end());
		sort(max_v.begin(), max_v.end());
		int best = 1e8;
		for (int i=2; i<=2*k; i++) {
			int cnt = n/2-pos[i];
			cnt += lower_bound(max_v.begin(), max_v.end(), i-k)-max_v.begin();
			cnt += lower_bound(min_v.begin(), min_v.end(), -i+1)-min_v.begin();
			best = min(best, cnt);
		}
		cout << best << endl;
	}
}