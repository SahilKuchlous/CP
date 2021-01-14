#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp (pair<int, int> &p1, pair<int, int> &p2) {
	return p1.first+p1.second > p2.first+p2.second;
}
int main () {
	int n, r;
	cin >> n >> r;
	pair<int, int> proj[n];
	for (int i=0; i<n; i++) {
		cin >> proj[i].first >> proj[i].second;
	}
	vector< pair<int, int> > pos, neg;
	for (int i=0; i<n; i++) {
		if (proj[i].second >= 0) {
			pos.push_back(proj[i]);
		} else {
			neg.push_back(proj[i]);
		}
	}
	sort(pos.begin(), pos.end());
	int rating = r;
	int o = 0;
	for (auto i: pos) {
		if (i.first <= rating) {
			rating += i.second;
			o++;
		} else {
			break;
		}
	}
	sort(neg.begin(), neg.end(), comp);
	int dp[rating+1], np[rating+1];
	for (int i=0; i<=rating; i++) {
		dp[i] = np[i] = 0;
	}
	int cnt = 0;
	for (auto i: neg) {
		for (int j=rating; j>=i.first; j--) {
			if (j+i.second < 0) break;
			np[j+i.second] = max(np[j+i.second], dp[j]+1);
		}
		for (int j=0; j<=rating; j++) {
			dp[j] = np[j];
			cnt = max(cnt, dp[j]);
		}
	}
	o += cnt;
	cout << (o == n ? "YES" : "NO") << endl;
}