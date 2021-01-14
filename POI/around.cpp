#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	long long dist[n], max_d = 0;
	for (int i=0; i<n; i++) {
		cin >> dist[i];
		max_d = max(max_d, dist[i]);
	}
	while (s--) {
		long long rng;
		cin >> rng;
		if (rng < max_d) {
			cout << "NIE" << endl;
			continue;
		}
		int nxt[n];
		nxt[0] = 0;
		long long cur_d = 0;
		for (int i=0; i<n; i++) {
			if (i != 0) {
				nxt[i] = nxt[i-1];
				cur_d -= dist[i-1];
			}
			while (cur_d+dist[nxt[i]] <= rng) {
				cur_d += dist[nxt[i]++];
				if (nxt[i] == n) nxt[i] = 0;
			}
		}
		int st = 0;
		for (int i=0; i<n; i++) {
			st = nxt[st];
		}
		int cur = st;
		int cyc = 0;
		int o = 0;
		while (true) {
			if (nxt[cur] <= cur) cyc++;
			cur = nxt[cur];
			o++;
			if (cyc+(cur>=st) >= 2)break;
		}
		cout << o << endl;
	}
}