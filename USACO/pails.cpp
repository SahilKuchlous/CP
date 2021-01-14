#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("pails.in");
ofstream fout("pails.out");
int main () {
	int x, y, t, m;
	fin >> x >> y >> t >> m;
	bool dp[x+1][y+1];
	for (int i=0; i<=x; i++) {
		for (int j=0; j<=y; j++) {
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	bool new_dp[x+1][y+1];
	for (int i=0; i<t; i++) {
		for (int j=0; j<=x; j++) {
			for (int k=0; k<=y; k++) {
				if (dp[j][k]) {
					new_dp[j][k] = true;
				} else {
					new_dp[j][k] = false;
				}
			}
		}
		for (int j=0; j<=x; j++) {
			for (int k=0; k<=y; k++) {
				if (dp[j][k]) {
					new_dp[x][k] = true;
					new_dp[0][k] = true;
					new_dp[j][y] = true;
					new_dp[j][0] = true;
					if (j > y-k) {
						new_dp[x-(y-k)][y] = true;
					} else {
						new_dp[0][j+k] = true;
					}
					if (k > x-j) {
						new_dp[x][k-(x-j)] = true;
					} else {
						new_dp[j+k][0] = true;
					}
				}
			}
		}
		for (int j=0; j<=x; j++) {
			for (int k=0; k<=y; k++) {
				// if (new_dp[j][k]) cout << j << " " << k << endl;
				dp[j][k] = new_dp[j][k];
			}
		}
	}
	int o = 10000;
	for (int i=0; i<=x; i++) {
		for (int j=0; j<=y; j++) {
			if (dp[i][j]) {
				// cout << i << " " << j << endl;
				o = min(o, abs(m-i-j));
			}
		}
	}
	fout << o << endl;
}