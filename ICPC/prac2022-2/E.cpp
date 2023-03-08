#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 205
#define MAXQ 20005
vector< pair<int, int> > risk;
int dist[MAXN][MAXN];
int best_dist[MAXN][MAXN];
vector< pair<int, pair<int, pair<int, int> > > > queries;
int ans[MAXQ];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int c=1; c<=t; c++) {
		risk.clear();
		queries.clear();

		int n, q;
		cin >> n >> q;
		int r;
		for (int i=0; i<n; i++) {
			cin >> r;
			risk.push_back(make_pair(r, i));
		}
		sort(risk.begin(), risk.end());
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> dist[i][j];
			}
		}
		int u, v, w;
		for (int i=0; i<q; i++) {
			cin >> u >> v >> w;
			u--; v--;
			queries.push_back(make_pair(w, make_pair(i, make_pair(u, v))));
		}
		sort(queries.begin(), queries.end());

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				best_dist[i][j] = dist[i][j];
			}
		}
		int risk_ptr = 0;
		for (auto q: queries) {
			while (risk_ptr < n && risk[risk_ptr].first <= q.first) {
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						best_dist[i][j] = min(best_dist[i][j], best_dist[i][risk[risk_ptr].second]+best_dist[risk[risk_ptr].second][j]);
					}
				}
				risk_ptr++;
			}
			ans[q.second.first] = best_dist[q.second.second.first][q.second.second.second];
		}
		cout << "Case #" << c << ":\n"; 
		for (int i=0; i<q; i++) {
			cout << ans[i] << endl;
		}
	}
}