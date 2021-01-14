#include <iostream>
using namespace std;
#define SQ 320
int n, m;
int par[100100];
int nxt[100100];
int cnt[100100];
int lst[100100];
void update (int i) {
	if (par[i]/SQ > i/SQ || par[i] == n) {
		nxt[i] = par[i];
		cnt[i] = 1;
		lst[i] = i;
		return;
	}
	nxt[i] = nxt[par[i]];
	cnt[i] = cnt[par[i]]+1;
	lst[i] = lst[par[i]];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> par[i];
		par[i] = min(n, i+par[i]);
	}
	for (int i=n-1; i>=0; i--) {
		update(i);
	}
	int ti, ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ti;
		if (ti == 0) {
			cin >> ai >> bi;
			ai--;
			par[ai] = min(n, ai+bi);
			update(ai);
			for (int j=1; j<=ai%SQ; j++) {
				update(ai-j);
			}
		} else {
			cin >> ai;
			ai--;
			int o1 = 0, o2 = 0;
			while (ai < n) {
				o1 = lst[ai];
				o2 += cnt[ai];
				ai = nxt[ai];
			}
			cout << o1+1 << " " << o2 << '\n';
		}
	}
}