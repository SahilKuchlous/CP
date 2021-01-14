#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100
int n, a, b;
int h[MAXN];
int cnt = 1e9;
vector<int> o, temp;
void solve (int pos, int cost) {
	if (cost >= cnt) return;
	if (pos == n-1) {
		if (h[n-1] < 0) {
			cnt = cost;
			o = temp;
		}
		return;
	}
	for (int i=0; i<=max(h[pos-1]/b, max(h[pos]/a, h[pos+1]/b))+1; i++) {
		if (h[pos-1]-b*i >= 0) continue;
		h[pos-1] -= b*i;
		h[pos] -= a*i;
		h[pos+1] -= b*i;
		for (int j=0; j<i; j++) temp.push_back(pos);
		solve(pos+1, cost+i);
		h[pos-1] += b*i;
		h[pos] += a*i;
		h[pos+1] += b*i;
		for (int j=0; j<i; j++) temp.pop_back();
	}
}
int main () {
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> h[i];
	}
	solve(1, 0);
	cout << cnt << endl;
	for (auto i: o) cout << i+1 << " ";
	cout << endl;
}