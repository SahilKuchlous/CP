#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fortmoo.in");
ofstream fout("fortmoo.out");
int main () {
	int n, m;
	fin >> n >> m;
	char grid[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			fin >> grid[i][j];
		}
	}
	int rowsum[n][m];
	for (int i=0; i<n; i++) {
		rowsum[i][0] = 0;
		if (grid[i][0] == 'X') rowsum[i][0]++;
		for (int j=1; j<m; j++) {
			rowsum[i][j] = rowsum[i][j-1];
			if (grid[i][j] == 'X') rowsum[i][j]++;
		}
	}
	int o = 0;
	int prev;
	for (int i=0; i<m; i++) {
		for (int j=i; j<m; j++) {
			prev = -1;
			for (int k=0; k<n; k++) {
				if (grid[k][i] == 'X' || grid[k][j] == 'X') {
					prev = k+1;
					continue;
				}
				if (rowsum[k][j]-rowsum[k][i] != 0) {
					if (prev == k) prev = k+1;
					continue;
				}
				if (prev == -1) prev = k;
				o = max(o, (k-prev+1)*(j-i+1));
			}
		}
	}
	fout << o << endl;
}