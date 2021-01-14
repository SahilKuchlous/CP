#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
int a[305];
int l[305][305][2], r[305][305][2];
int o = 0;
int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+2);
	int st = 0;
	for (int i=1; i<=n+1; i++) {
		if (a[i] == 0) {
			st = i;
			break;
		}
	}
	for (int i=0; i<=n+2; i++) {
		l[0][i][0] = r[i][n+2][0] = 1e9;
	}
	for (int k=1; k<=n; k++) {
		for (int i=1; i<=st; i++) {
			for (int j=st; j<=n+1; j++) {
				l[i][j][1] = min(l[i-1][j][0]+k*(a[i]-a[i-1]), r[i][j+1][0]+k*(a[j+1]-a[i]));
				r[i][j][1] = min(l[i-1][j][0]+k*(a[j]-a[i-1]), r[i][j+1][0]+k*(a[j+1]-a[j]));
			}
		}
		for (int i=1; i<=st; i++) {
			for (int j=st; j<=n+1; j++) {
				l[i][j][0] = l[i][j][1];
				r[i][j][0] = r[i][j][1];
			}
		}
		o = max(o, k*m-l[st][st][0]);
	}
	cout << o << endl;
}