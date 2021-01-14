#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("friendcross.in");
ofstream fout("friendcross.out");
int n, k;
int seq_l[100100], pos_l[100100];
int seq_r[100100], pos_r[100100];
vector<int> mst[400100];
vector<int> bit[400100];
int cnt[400100];
void create (int x, int l, int r) {
	if (l == r) {
		mst[x] = {seq_r[l]};
		bit[x].resize(2, 0);
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	merge(mst[2*x+1].begin(), mst[2*x+1].end(), mst[2*x+2].begin(), mst[2*x+2].end(), back_inserter(mst[x]));
	bit[x].resize(mst[x].size()+1, 0);
}
void update (int x, int l, int r, int p) {
	if (p < l || p > r) {
		return;
	}
	cnt[x]++;
	int ind = upper_bound(mst[x].begin(), mst[x].end(), seq_r[p])-mst[x].begin();
	while (ind <= r-l+1) {
		bit[x][ind]++;
		ind += ind & -ind;
	}
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p);
	update(2*x+2, m+1, r, p);
}
int query (int x, int l, int r, int p, int v, int t) {
	if (l > p) {
		return 0;
	}
	if (r <= p) {
		int ind = upper_bound(mst[x].begin(), mst[x].end(), v)-mst[x].begin();
		int ans = 0;
		while (ind > 0) {
			ans += bit[x][ind];
			ind -= ind & -ind;
		}
		if (t == 0) {
			return ans;
		} else {
			return cnt[x]-ans;
		}
	}
	int ans = 0;
	int m = (l+r)/2;
	ans += query(2*x+1, l, m, p, v, t);
	ans += query(2*x+2, m+1, r, p, v, t);
	return ans;
}
int main () {
	fin >> n >> k;
	for (int i=0; i<n; i++) {
		fin >> seq_l[i];
		seq_l[i]--;
		pos_l[seq_l[i]] = i;
	}
	for (int i=0; i<n; i++) {
		fin >> seq_r[i];
		seq_r[i]--;
		pos_r[seq_r[i]] = i;
	}
	create(0, 0, n-1);
	long long o = 0;
	for (int i=n-1; i>=0; i--) {
		if (seq_l[i]-k-1 >= 0) o += query(0, 0, n-1, pos_r[seq_l[i]], seq_l[i]-k-1, 0);
		if (seq_l[i]+k+1 < n) o += query(0, 0, n-1, pos_r[seq_l[i]], seq_l[i]+k, 1);
		update(0, 0, n-1, pos_r[seq_l[i]]);
	}
	fout << o << endl;
}