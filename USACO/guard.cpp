#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("guard.in");
ofstream fout("guard.out");
int n, h;
struct cow {
	long long h, w, s;
};
cow cows[30];
pair<long long, long long> dp[2000000];
long long o = -1;
int main () {
	fin >> n >> h;
	int hi, wi, si;
	for (int i=0; i<n; i++) {
		fin >> hi >> wi >> si;
		cows[i].h = hi;
		cows[i].w = wi;
		cows[i].s = si;
	}
	dp[0] = make_pair(0, 1e10);
	long long total_w, total_h, max_s;
	for (int i=1; i<(1<<n); i++) {
		total_w = total_h = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				total_w += cows[j].w;
				total_h += cows[j].h;
			}
		}
		max_s = -1;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				if (cows[j].s >= total_w-cows[j].w && dp[i-(1<<j)].second != -1) {
					max_s = max(max_s, min(cows[j].s-(total_w-cows[j].w), dp[i-(1<<j)].second));
				}
			}
		}
		dp[i] = make_pair(total_h, max_s);
		if (total_h >= h) o = max(o, max_s);
	}
	if (o == -1) {
		fout << "Mark is too tall" << endl;
	} else {
		fout << o << endl;
	}
}