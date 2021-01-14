#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
ifstream fin("redistricting.in");
ofstream fout("redistricting.out");
int main () {
	int n, k;
	fin >> n >> k;
	string inp;
	fin >> inp;
	int a[n+1];
	a[0] = 0;
	for (int i=0; i<n; i++) {
		a[i+1] = inp.at(i)=='H' ? 1:-1;
	}
	int dp[n+1];
	dp[0] = 0;
	int total[n+1];
	total[0] = 0;
	multiset< pair<int, int> > cur;
	cur.insert(make_pair(0, 0));
	for (int i=1; i<=n; i++) {
		total[i] = total[i-1]+a[i];
		pair<int, int> best = *cur.begin();
		dp[i] = best.first;
		if (best.second >= total[i]) {
			dp[i]++;
		}
		cur.insert(make_pair(dp[i], total[i]));
		if (i-k >= 0) {
			cur.erase(cur.find(make_pair(dp[i-k], total[i-k])));
		}
	}
	fout << dp[n] << endl;
}