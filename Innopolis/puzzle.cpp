#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAXN 305
#define MOD 1000000007
int n, l;
vector<int> a[3][3];
long long dp1[MAXN];
long long dp2[MAXN];
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l;
	map<string, int> conv;
	conv["in"] = 0;
	conv["none"] = 1;
	conv["out"] = 2;
	int ai;
	string bi, ci;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi >> ci;
		a[conv[bi]][conv[ci]].push_back(ai);
	}
	dp1[0] = 1;
	for (auto i: a[0][2]) {
		for (int j=l; j>=i; j--) {
			dp1[j] = (dp1[j]+dp1[j-i])%MOD;
		}
	}
	dp2[0] = 1;
	for (auto i: a[2][0]) {
		for (int j=l; j>=i; j--) {
			dp2[j] = (dp2[j]+dp2[j-i])%MOD;
		}
	}
	for (auto i: a[1][1]) {
		if (i == l) o++;
	}
	for (auto i: a[1][0]) {
		for (auto j: a[2][1]) {
			if (i+j > l) continue;
			o = (o+dp2[l-i-j])%MOD;
		}
	}
	for (auto i: a[1][2]) {
		for (auto j: a[0][1]) {
			if (i+j > l) continue;
			o = (o+dp1[l-i-j])%MOD;
		}
	}
	cout << o << endl;
}