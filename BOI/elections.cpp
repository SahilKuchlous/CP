#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<int, int> a[n];
	int total = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		total += a[i].first;
	}
	sort(a, a+n, greater< pair<int, int> >());
	pair<int, int> dp[total+1];
	for (int i=0; i<=total; i++) {
		dp[i] = make_pair(-1, -1);
	}
	dp[0] = make_pair(0, 0);
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=total/2; j>=0; j--) {
			if (dp[j].first > -1 && j+a[i].first <= total && dp[j+a[i].first].first == -1) {
				dp[j+a[i].first] = make_pair(j, a[i].second);
				ans = max(ans, j+a[i].first);
			}
		}
	}
	vector<int> o;
	int cur = ans;
	while (cur != 0) {
		o.push_back(dp[cur].second);
		cur = dp[cur].first;
	}
	cout << o.size() << endl;
	for (int i=0; i<o.size(); i++) {
		cout << o[i]+1 << " ";
	}
	cout << endl;
}