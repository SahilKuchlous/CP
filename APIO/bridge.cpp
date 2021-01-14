#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
bool comp (const pair<int, int> p1, const pair<int, int> p2) {
	return p1.first+p1.second < p2.first+p2.second;
}
priority_queue<int> lpq;
priority_queue< int, vector<int>, greater<int> > rpq;
long long lsum, rsum;
void insert (int x) {
	if (lpq.size() == 0 || x <= lpq.top()) {
		lpq.push(x);
		lsum += x;
	} else {
		rpq.push(x);
		rsum += x;
	}
	if (rpq.size()+1 < lpq.size()) {
		int cur = lpq.top();
		lpq.pop();
		rpq.push(cur);
		lsum -= cur;
		rsum += cur;
	}
	if (lpq.size() < rpq.size()) {
		int cur = rpq.top();
		rpq.pop();
		lpq.push(cur);
		rsum -= cur;
		lsum += cur;
	}
}
int main () {
	int k, n;
	cin >> k >> n;
	char ai, ci;
	int bi, di;
	long long o = 0;
	vector< pair<int, int> > pts;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi >> ci >> di;
		if (ai != ci) {
			pts.push_back(make_pair(min(bi, di), max(bi, di)));
		} else {
			o += abs(bi-di);
		}
	}
	n = pts.size();
	o += n;
	pts.push_back(make_pair(0, 0));
	sort(pts.begin(), pts.end(), comp);
	long long pre[n+1];
	pre[0] = 0;
	lsum = rsum = 0;
	for (int i=1; i<=n; i++) {
		insert(pts[i].first);
		insert(pts[i].second);
		pre[i] = rsum-lsum;
	}
	long long ans = pre[n];
	if (k == 2) {
		while (lpq.size() > 0) lpq.pop();
		while (rpq.size() > 0) rpq.pop();
		lsum = rsum = 0;
		for (int i=n; i>0; i--) {
			insert(pts[i].first);
			insert(pts[i].second);
			ans = min(ans, pre[i-1]+rsum-lsum);
		}
	}
	o += ans;
	cout << o << endl;
}