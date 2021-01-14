#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
ifstream fin("time.in");
ofstream fout("time.out");
long long n, m, c;
int score[1100];
set<int> adj[1100];
int main () {
	fin >> n >> m >> c;
	for (int i=1; i<=n; i++) {
		fin >> score[i];
	}
	int a, b;
	for (int i=0; i<m; i++) {
		fin >> a >> b;
		adj[a].insert(b);
	}
	long long dp[n+1];
	dp[1] = 0;
	for (int i=2; i<=n; i++) {
		dp[i] = -1e11;
	}
	long long t = 1;
	long long dp_new[n+1];
	while (t <= 1000) {
		for (int i=1; i<=n; i++) {
			dp_new[i] = dp[i];
			for (auto j: adj[i]) {
				dp_new[i] = max(dp_new[i], dp[j]+score[i]+c*(t-1)*(t-1)-c*t*t);
			}
		}
		for (int i=1; i<=n; i++) {
			dp[i] = dp_new[i];
		}
		t++;
	}
	fout << dp[1] << endl;
}