#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 55
#define MOD 1000000007
int n;
int s[MAXN];
int t[MAXN];
int cnt[MAXN];
long long dp[MAXN][MAXN][MAXN][MAXN];
long long o = 0;

bool used_s[MAXN], used_t[MAXN];
void solve (int cnt) {
	if (cnt == n+1) {
		bool valid = true;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (!used_s[i] && !used_t[j] && s[i] <= t[j]) valid = false;
			}
		}
		if (valid) o++;
		return;
	}
	used_t[cnt] = false;
	solve(cnt+1);
	used_t[cnt] = true;
	for (int i=1; i<=n; i++) {
		if (!used_s[i] &&  s[i] <= t[cnt]) {
			used_s[i] = true;
			solve(cnt+1);
			used_s[i] = false;
		}
	}
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
	}
	sort(s+1, s+n+1, greater<int>());
	for (int i=1; i<=n; i++) {
		cin >> t[i];
	}
	sort(t+1, t+n+1, greater<int>());
	for (int i=1; i<=n; i++) {
		cnt[i] = n;
		for (int j=1; j<=n; j++) {
			if (s[i] > t[j]) {
				cnt[i] = j-1;
				break;
			}
		}
		// cout << cnt[i] << " ";
	}
	// cout << endl;
	dp[0][0][0][0] = 1;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=i; j++) {
			for (int k=0; k<=i; k++) {
				for (int l=0; l<=i; l++) {
					if (cnt[i]-j-l > 0) dp[i][j+1][k][l] = (dp[i][j+1][k][l]+dp[i-1][j][k][l]*(cnt[i]-j-l)%MOD)%MOD;
					// if (dp[i-1][j][k][l]*(cnt[i]-j-l) < 0) cout << "E" << endl;
					// if (i == 4 && j+1 == 3 && k == 2 && l == 0) cout << dp[i][j+1][k][l] << endl;
					dp[i][j+1][k][l] = (dp[i][j+1][k][l]+dp[i-1][j][k][l+1]*(l+1)%MOD)%MOD;
					// if (dp[i-1][j][k][l+1]*(l+1) < 0) cout << "E" << endl;
					// if (i == 4 && j+1 == 3 && k == 2 && l == 0) cout << dp[i][j+1][k][l] << endl;
					if (cnt[i]-j > 0) dp[i][j][i][cnt[i]-j] = (dp[i][j][i][cnt[i]-j]+dp[i-1][j][k][l])%MOD;
					// if (i == 4 && j == 3 && k == 2 && l == 0) cout << dp[i][j][k][l] << endl;
					// if (dp[i-1][j][k][l] < 0) cout << "E" << endl;
				}
			}
		}
	}
	// cout << dp[4][3][2][0] << endl;
	// cout << dp[3][2][2][0] << endl;
	// cout << dp[2][1][2][1] << endl;
	// cout << dp[3][2][2][1] << endl;
	for (int j=0; j<=n; j++) {
		for (int k=0; k<=n; k++) {
			o = (o+dp[n][j][k][0])%MOD;
		}
		// cout << j << " " << o << endl;
	}
	cout << o << endl;
	o = 0;
	solve(1);
	cout << o << endl;
}

/*
#include <iostream>
using namespace std;
#define MAXN 3005
int n;
int s[MAXN];
int t[MAXN];
bool used_s[MAXN], used_t[MAXN];
int o = 0;
void solve (int cnt) {
	if (cnt == n) {
		bool valid = true;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!used_s[i] && !used_t[j] && s[i] <= t[j]) valid = false;
			}
		}
		if (valid) o++;
		return;
	}
	used_t[cnt] = false;
	solve(cnt+1);
	used_t[cnt] = true;
	for (int i=0; i<n; i++) {
		if (!used_s[i] &&  s[i] <= t[cnt]) {
			used_s[i] = true;
			solve(cnt+1);
			used_s[i] = false;
		}
	}
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	for (int i=0; i<n; i++) {
		cin >> t[i];
	}
	solve(0);
	cout << o << endl;
}
*/