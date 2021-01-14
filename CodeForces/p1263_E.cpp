#include <iostream>
using namespace std;
int segtree[4000100][3];
void update (int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		segtree[x][0] = v;
		segtree[x][1] = min(0, v);
		segtree[x][2] = max(0, v);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x][0] = segtree[2*x+1][0]+segtree[2*x+2][0];
	segtree[x][1] = min(segtree[2*x+1][1], segtree[2*x+1][0]+segtree[2*x+2][1]);
	segtree[x][2] = max(segtree[2*x+1][2], segtree[2*x+1][0]+segtree[2*x+2][2]);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	char moves[n];
	for (int i=0; i<n; i++) {
		cin >> moves[i];
	}
	int pos = 0;
	for (int i=0; i<n; i++) {
		if (moves[i] == 'R') {
			pos++;
		} else if (moves[i] == 'L') {
			pos--;
			pos = max(0, pos);
		} else if (moves[i] == '(') {
			update(0, 0, n-1, pos, 1);
		} else if (moves[i] == ')') {
			update(0, 0, n-1, pos, -1);
		} else {
			update(0, 0, n-1, pos, 0);
		}
		if (segtree[0][0] == 0 && segtree[0][1] == 0) {
			cout << segtree[0][2] << " ";
		} else {
			cout << -1 << " ";
		}
	}
	cout << endl;
}