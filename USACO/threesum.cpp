#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;
ifstream fin("threesum.in");
ofstream fout("threesum.out");
long long dp[5000][5000];
int main () {
	int n, q;
	fin >> n >> q;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			dp[i][j] = 0;
		}
	}
	int freq[2000001];
	for (int i=0; i<2000001; i++) {
		freq[i] = 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int ind = 1000000-a[i]-a[j];
			if (ind >= 0 && ind <= 2000000) {
				dp[i][j] = freq[ind];
			}
			freq[1000000+a[j]]++;
		}
		for (int j=i+1; j<n; j++) {
			freq[1000000+a[j]]--;
		}
	}
	for (int dif=1; dif<n; dif++) {
		for (int i=0; i<n-dif; i++) {
			dp[i][i+dif] += dp[i][i+dif-1] + dp[i+1][i+dif] - dp[i+1][i+dif-1];
		}
	}
	int right, left;
	for (int i=0; i<q; i++) {
		fin >> right >> left;
		fout << dp[right-1][left-1] << endl;
	}
}