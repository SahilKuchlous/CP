#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
pair<int, int> a[100100];
long long o[100100][3];
vector<long long> cur;
int main () {
	cin >> n;
	int si, ti;
	for (int i=0; i<n; i++) {
		cin >> si >> ti;
		a[i] = make_pair(si+ti, ti-si);
	}
	sort(a, a+n);
	for (int i=0; i<n; i++) {
		long long x = a[i].first, y = -a[i].second;
		int pos = lower_bound(cur.begin(), cur.end(), y)-cur.begin();
		if (pos == cur.size()) {
			cur.push_back(y);
		} else {
			cur[pos] = y;
		}
		o[i][0] = (x+y)/2;
		o[i][1] = (x-y)/2;
		o[i][2] = pos+1;
	}
	cout << cur.size() << endl;
	for (int i=0; i<n; i++) {
		cout << o[i][0] << " " << o[i][1] << " " << o[i][2] << endl;
	}
}