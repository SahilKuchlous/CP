#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
int main () {
	int n;
	cin >> n;
	int time[n], dura[n];
	for (int i=0; i<n; i++) {
		cin >> time[i] >> dura[i];
	}
	set< pair<int, int> > pre;
	set< pair<int, int>, greater< pair<int, int> > > cur;
	set< int, greater<int> > post;
	post.insert(0);
	int dp[n];
	for (int i=0; i<n; i++) {
		dp[i] = *post.begin();
		if (cur.size() > 0) {
			int ind = cur.begin()->second;
			dp[i] = max(dp[ind]+i-(ind+time[ind])-1, dp[i]);
		}
		pre.insert(make_pair(i+time[i], i));
		while (pre.size() > 0 && pre.begin()->first == i) {
			cur.insert(make_pair(dp[pre.begin()->second]-i, pre.begin()->second));
			pre.erase(pre.begin());
		}
		while (cur.size() > 0 && cur.begin()->second+time[cur.begin()->second]+dura[cur.begin()->second] <= i) {
			post.insert(dp[cur.begin()->second]+dura[cur.begin()->second]);
			cur.erase(cur.begin());
		}
	}
	int ans = *post.begin();
	if (cur.size() > 0) {
		int ind = cur.begin()->second;
		ans = max(dp[ind]+n-(ind+time[ind])-1, ans);
	}
	cout << ans << endl;
}