#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[m];
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	vector<long long> sa(n+1);
	sa[0] = 0;
	for (int i=1; i<=n; i++) {
		sa[i] = sa[i-1]+a[i-1];
	}
	vector<long long> sb(m+1);
	sb[0] = 0;
	for (int i=1; i<=m; i++) {
		sb[i] = sb[i-1]+b[i-1];
	}
	int o = 0;
	for (int i=0; i<=n; i++) {
		if (k-sa[i] >= 0) o = max((long)o, i+(upper_bound(sb.begin(), sb.end(), k-sa[i])-sb.begin()-1));
	}
	cout << o << endl;
}