#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <time.h>
using namespace std;
mt19937 rnd(time(0));
int MOD;
int n, q;
vector<int> s[10005];
vector<int> e[10005];
bool pos[10005];
long long dp[10005];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	MOD = 5e8 + rnd() % (int) 5e8;
	cin >> n >> q;
	int ai, bi, ci;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		s[ai].push_back(ci);
		e[bi].push_back(ci);
	}
	dp[0] = 1;
	for (int i=0; i<n; i++) {
		for (auto j: s[i]) {
			for (int k=n; k>=j; k--) {
				dp[k] = (dp[k]+dp[k-j])%MOD;
			}
		}
		for (int j=0; j<=n; j++) {
			if (dp[j] > 0) pos[j] = true;
		}
		for (auto j: e[i]) {
			for (int k=j; k<=n; k++) {
				dp[k] = (dp[k]-dp[k-j]+MOD)%MOD;
			}
		}
	}
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		if (pos[i]) cnt++;
	}
	cout << cnt << endl;
	for (int i=1; i<=n; i++) {
		if (pos[i]) cout << i << " ";
	}
	cout << endl;
}