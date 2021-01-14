#include <iostream>
#include <set>
using namespace std;
int par[110];
long long a[110];
int c = 0;
int n;
void dfs (int x) {
	cout << a[x] << " ";
	c++;
	if (c < n) {
		dfs(par[x]);
	}
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	set<int> cov;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (2*a[i] == a[j]) {
				par[i] = j;
				cov.insert(j);
			}
			if (a[i]%3 == 0 && a[i]/3 == a[j]) {
				par[i] = j;
				cov.insert(j);
			}
		}
	}
	for (int i=0; i<n; i++) {
		if (cov.find(i) == cov.end()) {
			dfs(i);
			break;
		}
	}
	cout << endl;
}