#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, w;
long long segtree[4000000];
void update (int x, int l, int r, int a, int b, int v) {
	if (b < l || r < a) return;
	if (a <= l && r <= b) {
		segtree[x] += v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
}
long long query (int x, int l, int r, int p) {
	if (p < l || r < p) return 0;
	long long ttl = segtree[x];
	if (l == r) return ttl;
	int m = (l+r)/2;
	ttl += query(2*x+1, l, m, p);
	ttl += query(2*x+2, m+1, r, p);
	return ttl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> w;
	int len, ai;
	vector<int> cur;
	for (int i=0; i<n; i++) {
		cur.clear();
		cin >> len;
		for (int j=0; j<len; j++) {
			cin >> ai;
			cur.push_back(ai);
		}
		if (2*len >= w) {
			multiset<int> ord;
			for (int i=0; i<w; i++) {
				if (i < len) {
					ord.insert(-cur[i]);
				}
				if (i+len > w) {
					ord.erase(ord.find(-cur[len-(w-i+1)]));
				}
				int best = -*ord.begin();
				if (max(i, w-i-1) >= len) best = max(0, best);
				update(0, 0, w-1, i, i, best);
			}
		} else {
			int best = 0;
			for (int i=0; i<len; i++) {
				best = max(best, cur[i]);
				update(0, 0, w-1, i, i, best);
			}
			best = 0;
			for (int i=0; i<len; i++) {
				best = max(best, cur[len-i-1]);
				update(0, 0, w-1, w-i-1, w-i-1, best);
			}
			update(0, 0, w-1, len, w-len-1, best);
		}
	}
	for (int i=0; i<w; i++) {
		cout << query(0, 0, w-1, i) << " ";
	}
	cout << endl;
}