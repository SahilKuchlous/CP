#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("nochange.in");
ofstream fout("nochange.out");
int main () {
	int k, n;
	fin >> k >> n;
	int coins[k];
	for (int i=0; i<k; i++) {
		fin >> coins[i];
	}
	int cost[n];
	for (int i=0; i<n; i++) {
		fin >> cost[i];
	}
	vector<int> psum(n+1);
	psum[0] = 0;
	for (int i=0; i<n; i++) {
		psum[i+1] = psum[i]+cost[i];
	}
	int end[(int)pow(2, k)];
	for (int i=0; i<pow(2, k); i++) {
		end[i] = 0;
		for (int j=0; j<k; j++) {
			if (i & (1<<j)) {
				int ind = i-(1<<j);
				end[i] = max(end[i], (int)(upper_bound(psum.begin(), psum.end(), psum[end[ind]]+coins[j])-psum.begin()-1));
			}
		}
	}
	long long o = -1;
	long long ans;
	for (int i=0; i<pow(2, k); i++) {
		ans = 0;
		if (end[i] == n) {
			for (int j=0; j<k; j++) {
				if (!(i & (1<<j))) {
					ans += coins[j];
				}
			}
			o = max(o, ans);
		}
	}
	fout << o << endl;
}