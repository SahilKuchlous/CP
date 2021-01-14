#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
struct edge {
	int wt;
	int a, b;
	bool operator < (const edge e) const {
		return wt < e.wt;
	}
};
int dsu[500100];
long long score[500100];
int hist[500100];
int root (int a) {
	if (dsu[a] == a) return a;
	dsu[a] = dsu[dsu[a]];
	return root(dsu[a]);
}
int main () {
	int n, m, h;
	cin >> n >> m >> h;
	edge edges[n*(m-1)+m*(n-1)];
	int cnt = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m-1; j++) {
			cin >> edges[cnt].wt;
			edges[cnt].a = i*m+j;
			edges[cnt].b = i*m+(j+1);
			cnt++;
		}
	}
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m; j++) {
			cin >> edges[cnt].wt;
			edges[cnt].a = i*m+j;
			edges[cnt].b = (i+1)*m+j;
			cnt++;
		}
	}
	sort(edges, edges+cnt);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			dsu[i*m+j] = i*m+j;
			score[i*m+j] = 0;
			hist[i*m+j] = -1;
		}
	}
	for (int i=0; i<cnt; i++) {
		int r1 = root(edges[i].a); int r2 = root(edges[i].b);
		if (r1 == r2) continue;
		score[r1] = (score[r1]+edges[i].wt-hist[r1])%MOD;
		score[r2] = (score[r2]+edges[i].wt-hist[r2])%MOD;
		score[r1] = (score[r1]*score[r2])%MOD;
		dsu[r2] = r1;
		hist[r1] = edges[i].wt;
	}
	int r = root(0);
	cout << (score[r]+h-hist[r])%MOD << endl;
}