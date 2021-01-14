#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, t, k;
	cin >> n >> t >> k;
	long long lvl[k];
	for (int i=0; i<k; i++) {
		cin >> lvl[i];
	}
	priority_queue< pair<long long, long long> > pq;
	vector<int> cur_lvl = {0};
	pq.push({-lvl[0], 0});
	long long o = 0;
	while (n > 0) {
		pair<long long, long long> cur = pq.top();
		pq.pop();
		long long cost = -cur.first;
		long long cnt = min(4*cur.second+4, n);
		o += cost*cnt;
		n -= cnt;
		if (cur_lvl[cur.second] < k-1) {
			cur_lvl[cur.second]++;
			pq.push({-lvl[cur_lvl[cur.second]]-cur.second*t, cur.second});
		}
		if (cur_lvl.size() == cur.second+1) {
			cur_lvl.push_back(0);
			pq.push({-lvl[0]-(cur.second+1)*t, cur.second+1});
		}
	}
	cout << o << endl;
}