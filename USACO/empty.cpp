#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("empty.in");
ofstream fout("empty.out");
int main () {
	int n, k;
	fin >> n >> k;
	int cows[n];
	for (int i=0; i<n; i++) {
		cows[i] = 0;
	}
	long long xi, yi, ai, bi;
	long long cur;
	for (int i=0; i<k; i++) {
		fin >> xi >> yi >> ai >> bi;
		cur = bi;
		for (int j=0; j<yi; j++) {
			cur += ai;
			cur %= n;
			cows[cur] += xi;
		}
	}
	cur = 0;
	bool taken[n];
	for (int i=0; i<n; i++) {
		taken[i] = false;
	}
	for (int i=0; i<n; i++) {
		if (cur < i) cur = i;
		while (cows[i] > 0) {
			if (!taken[cur%n]) {
				taken[cur%n] = true;
				cows[i]--;
			}
			cur++;
		}
	}
	int o = 0;
	for (int i=0; i<n; i++) {
		if (!taken[i]) {
			o = i;
			break;
		}
	}
	fout << o << endl;
}