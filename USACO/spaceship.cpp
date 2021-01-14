#include <iostream>
using namespace std;
#define MAXN 20
#define MOD 1000000007
int n, k, q;
bool adj[MAXN][MAXN];
long long cnt1[MAXN][MAXN][MAXN*MAXN];
int main () {
	cin >> n >> k >> q;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> inp;
			adj[i][j] = inp-'0';
		}
	}
	for (int i=0; i<n; i++) {
		cnt1[i][i][0] = 1;
	}
	for (int d=1; d<=k*(k+1)/2; d++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				for (int k=0; k<n; k++) {
					if (adj[k][j]) cnt1[i][j][d] = (cnt1[i][j][d]+cnt1[i][k][d-1])%MOD;
				}
			}
		}
	}
	int a, s, b, e;
	while (q--) {
		cin >> a >> s >> b >> e;
		s--; e--;
		long long o = 0;
		if (a == b && s == e) o++;
		if (a == k) {
			cout << o << endl;
			continue;
		}
		for (int i=1; i<=k*(k+1)/2-s*(s-1)/2; i++) {
			if (i == 1 && a == b) continue;
			o = (o+cnt1[s][e][i])%MOD;
		}
		cout << o << endl;
	}
}