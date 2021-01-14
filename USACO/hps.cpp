#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("hps.in");
ofstream fout("hps.out");
int main () {
	int n;
	fin >> n;
	int a[n];
	char inp;
	for (int i=0; i<n; i++) {
		fin >> inp;
		if (inp == 'H') {
			a[i] = 0;
		} else if (inp == 'P') {
			a[i] = 1;
		} else if (inp == 'S') {
			a[i] = 2;
		}
	}
	int pre[n+1][3];
	pre[0][0] = pre[0][1] = pre[0][2] = 0;
	for (int i=1; i<=n; i++) {
		pre[i][0] = pre[i-1][0];
		pre[i][1] = pre[i-1][1];
		pre[i][2] = pre[i-1][2];
		pre[i][a[i-1]]++;
	}
	int best = 0;
	for (int i=0; i<n; i++) {
		int score = max(max(pre[i][0], pre[i][1]), pre[i][2]) + max(max(pre[n][0]-pre[i][0], pre[n][1]-pre[i][1]), pre[n][2]-pre[i][2]);
		best = max(best, score);
	}
	fout << best << endl;
}