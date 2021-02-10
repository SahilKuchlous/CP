#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 200005
#define MOD 1000000007
int n;
pair<int, int> dolls[MAXN];
vector< pair<int, int> > in_ord, out_ord;
int cost[MAXN];
long long cnt[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> dolls[i].second >> dolls[i].first;
		in_ord.push_back(make_pair(dolls[i].first, i));
		out_ord.push_back(make_pair(dolls[i].second, i));
	}
	sort(in_ord.begin(), in_ord.end());
	sort(out_ord.begin(), out_ord.end());
	int ptr = 0;
	int best_val = 0;
	long long best_cnt = 1;
	for (auto i: in_ord) {
		while (ptr < n && out_ord[ptr].first <= i.first) {
			int cur = cost[out_ord[ptr].second]-out_ord[ptr].first;
			if (cur < best_val) {
				best_val = cur;
				best_cnt = cnt[out_ord[ptr].second];
			} else if (cur == best_val) {
				best_cnt = (best_cnt+cnt[out_ord[ptr].second])%MOD;
			}
			ptr++;
		}
		cost[i.second] = best_val + i.first;
		cnt[i.second] = best_cnt;
	}
	long long o = 0;
	int min_cost = 1e9;
	for (int i=ptr; i<n; i++) {
		if (cost[out_ord[i].second] < min_cost) {
			min_cost = cost[out_ord[i].second];
			o = cnt[out_ord[i].second];
		} else if (cost[out_ord[i].second] == min_cost) {
			o = (o+cnt[out_ord[i].second])%MOD;
		}
	}
	cout << o << endl;
}