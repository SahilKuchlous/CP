#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MOD 1000000007
int n, x, y;
vector<int> a;
int lim_a[MAXN], lim_b[MAXN];
int seq_a[MAXN], seq_b[MAXN];
long long dp_a[MAXN], dp_b[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y;
	int inp;
	a.push_back(-1e9);
	for (int i=0; i<n; i++) {
		cin >> inp;
		a.push_back(inp);
	}
	sort(a.begin(), a.end());
	int ptr = 0;
	for (int i=1; i<=n; i++) {
		while (a[i]-a[ptr+1] >= x) {
			ptr++;
		}
		lim_a[i] = ptr;
	}
	ptr = 0;
	for (int i=1; i<=n; i++) {
		while (a[i]-a[ptr+1] >= y) {
			ptr++;
		}
		lim_b[i] = ptr;
	}
	ptr = 0;
	for (int i=1; i<=n; i++) {
		if (a[i]-a[i-1] < x) ptr = i;
		seq_a[i] = ptr;
	}
	ptr = 0;
	for (int i=1; i<=n; i++) {
		if (a[i]-a[i-1] < y) ptr = i;
		seq_b[i] = ptr;
	}
	dp_a[1] = dp_b[1] = 1;
	for (int i=2; i<=n; i++) {
		if (lim_a[i] == i-1) dp_a[i] = dp_a[i-1];
		if (lim_a[i] >= seq_b[i-1]-1) {
			dp_a[i] = (dp_a[i]+dp_b[min(i-1, lim_a[i]+1)])%MOD;
		}
		if (lim_b[i] == i-1) dp_b[i] = dp_b[i-1];
		if (lim_b[i] >= seq_a[i-1]-1) {
			dp_b[i] = (dp_b[i]+dp_a[min(i-1, lim_b[i]+1)])%MOD;
		}
	}
	cout << (dp_a[n]+dp_b[n])%MOD << endl;
}