#include <iostream>
#include <algorithm>
using namespace std;
int n, l, u;
int delta[100100];
long long presum[100100];
long long premax[100100], premin[100100];
long long sum_l[100100], sum_u[100100];
int bin_u[100100][20], bin_d[100100][20];
struct query {
	int id;
	int s, e, init;
	int ans;
	bool operator < (const q1) const {
		return e < q1.e;
	}
};
int main () {
	cin >> n >> l >> u;
	for (int i=0; i<n; i++) {
		cin >> delta[i];
	}
	for (int i=1; i<=n; i++) {
		presum[i] = presum[i-1]+delta[i-1];
		premax[i] = max(premax[i-1], presum[i]);
		premin[i] = min(premin[i-1], presum[i]);
	}
	for (int i=0; i<n; i++) {
		bin_u[i][0] = lower_bound(premax)
	}
	int q;
	cin >> q;
	query queries[q];
	for (int i=0; i<q; i++) {
		cin >> queries[i].s >> queries[i].e >> queries[i].init;
		queries[i].s--; queries[i].e--;
		queries[i].id = i;
	}
	sort(queries, queries+q);
}