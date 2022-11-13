#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005

int n;
int a[MAXN];
int b[MAXN];
int k, o;

int seg_cnt[4*MAXN];
long long seg_sum[4*MAXN];

void ins (int x, int l, int r, int p, int v) {
	if (p < l || p > r) return;
	if (l == r) {
		seg_cnt[x] = 1;
		seg_sum[x] = v;
		return;
	}
	int m = (l+r)/2;
	ins(2*x+1, l, m, p, v);
	ins(2*x+2, m+1, r, p, v);

	seg_cnt[x] = seg_cnt[2*x+1]+seg_cnt[2*x+2];
	seg_sum[x] = seg_sum[2*x+1]+seg_sum[2*x+2];
}

void del (int x, int l, int r, int p) {
	if (p < l || p > r) return;
	if (l == r) {
		seg_cnt[x] = 0;
		seg_sum[x] = 0;
		return;
	}
	int m = (l+r)/2;
	del(2*x+1, l, m, p);
	del(2*x+2, m+1, r, p);

	seg_cnt[x] = seg_cnt[2*x+1]+seg_cnt[2*x+2];
	seg_sum[x] = seg_sum[2*x+1]+seg_sum[2*x+2];
}

long long query (int x, int l, int r, int c, long long s) {
	if (o == 0) return 0;
	if (l == r) {
		return s+seg_sum[x];
	}
	int m = (l+r)/2;
	if (c+seg_cnt[2*x+2] >= o) return query(2*x+2, m+1, r, c, s);
	return query(2*x+1, l, m, c+seg_cnt[2*x+2], s+seg_sum[2*x+2]);
}

int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	cin >> k >> o;

	vector< pair<int, int> > ord;
	for (int i=0; i<n; i++) {
		ord.push_back(make_pair(b[i], i));
	}
	sort(ord.begin(), ord.end());
	int ind[n];
	for (int i=0; i<n; i++) {
		ind[ord[i].second] = i;
	}

	long long cur_sum = 0;
	long long max_sum = 0;
	for (int i=0; i<k; i++) {
		cur_sum += a[i];
		ins(0, 0, n-1, ind[i], b[i]);
	}
	max_sum = cur_sum+query(0, 0, n-1, 0, 0);
	for (int i=0; i<k; i++) {
		cur_sum += a[n-i-1];
		cur_sum -= a[k-i-1];
		ins(0, 0, n-1, ind[n-i-1], b[n-i-1]);
		del(0, 0, n-1, ind[k-i-1]);
		max_sum = max(max_sum, cur_sum+query(0, 0, n-1, 0, 0));
	}
	cout << max_sum << endl;
}