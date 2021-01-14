#include <iostream>
#include <vector>
using namespace std;
int seg[200000][4];
int a[50000];
void buildSeg (int node, int start, int end) {
	if (start == end) {
		seg[node][0] = max(0, a[start]);
		seg[node][1] = a[start];
		seg[node][2] = a[start];
		seg[node][3] = a[start];
	} else {
		int mid = (start+end)/2;
		buildSeg(2*node+1, start, mid);
		buildSeg(2*node+2, mid+1, end);
		seg[node][0] = max(0, seg[2*node+1][2]+seg[2*node+2][1]);
		seg[node][1] = max(seg[2*node+1][1], seg[2*node+1][3]+seg[2*node+2][1]);
		seg[node][2] = max(seg[2*node+1][2]+seg[2*node+2][3], seg[2*node+2][2]);
		seg[node][3] = seg[2*node+1][3]+seg[2*node+2][3];
	}
}
void query (int x, int y, int l, int r, int node, int o[4]) {
	if (l >= x && r <= y) {
		for (int i=0; i<4; i++) {
			o[i] = seg[node][i];
		}
		return;
	}
	if (l < x && r > y) {
		for (int i=0; i<4; i++) {
			o[i] = INT_MAX;
		}
		return;
	}
	int seg1[4];
	query(x, y, l, (r+l)/2, node*2+1, seg1);
	int seg2[4];
	query(x, y, (r+l)/2+1, r, node*2+2, seg2);
	if (seg1[0] == INT_MAX) {
		for (int i=0; i<4; i++) {
			o[i] = seg2[i];
		}
		return;
	}
	if (seg2[0] == INT_MAX) {
		for (int i=0; i<4; i++) {
			o[i] = seg1[i];
		}
		return;
	}
	o[0] = max(0, seg1[2]+seg2[1]);
	o[1] = max(seg1[1], seg1[3]+seg2[1]);
	o[2] = max(seg1[2]+seg2[3], seg2[2]);
	o[3] = seg1[3]+seg2[3];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	buildSeg(0, 0, n-1);
	int m;
	cin >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		int o[4];
		query(x, y, 0, n-1, 0, o);
		cout << max_element(o, o+3) << endl;
	}
}