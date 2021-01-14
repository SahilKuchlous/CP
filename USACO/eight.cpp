#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("eight.in");
ofstream fout("eight.out");
int old_down_loc[300][300];
int new_down_loc[300][300];
int old_down_fin[300][300];
int new_down_fin[300][300];
int old_up_loc[300][300];
int new_up_loc[300][300];
int old_up_fin[300][300];
int new_up_fin[300][300];
bool done[300][300];
long long o = 0;
int bi, bj, bk, up, down;
int main () {
	int n;
	fin >> n;
	bool grid[n][n];
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			fin >> inp;
			if (inp == '.') {
				grid[i][j] = true;
			} else {
				grid[i][j] = false;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (grid[i][j]) {
				old_down_loc[i][j] = old_up_fin[i][j] = old_up_loc[i][j] = old_up_fin[i][j] = 0;
				done[i][j] = false;
			} else {
				old_down_loc[i][j] = old_up_fin[i][j] = old_up_loc[i][j] = old_up_fin[i][j] = -1;
				done[i][j] = true;
			}
		}
	}
	for (int k=1; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n-k; j++) {
				new_down_loc[i][j] = new_up_fin[i][j] = new_up_loc[i][j] = new_up_fin[i][j] = -1;
				done[i][j] = done[i][j] || !grid[i][j+k];
			}
		}
		for (int j=0; j<n-k; j++) {
			if (!done[n-1][j]) new_down_loc[n-1][j] = new_down_fin[n-1][j] = 0;
		}
		for (int i=n-2; i>=0; i--) {
			for (int j=0; j<n-k; j++) {
				if (grid[i][j] && grid[i][j+k] && (!done[i][j] || new_down_loc[i+1][j] > -1)) new_down_loc[i][j] = new_down_loc[i+1][j]+1;
				if (!done[i][j]) new_down_fin[i][j] = max(0, new_down_loc[i][j]-1)*max(0, k-1);
			}
		}
		for (int j=0; j<n-k; j++) {
			if (!done[0][j]) new_up_loc[0][j] = new_up_fin[0][j] = 0;
		}
		for (int i=1; i<n; i++) {
			for (int j=0; j<n-k; j++) {
				if (grid[i][j] && grid[i][j+k] && (!done[i][j] || new_up_loc[i-1][j] > -1)) new_up_loc[i][j] = new_up_loc[i-1][j]+1;
				if (!done[i][j]) new_up_fin[i][j] = max(0, new_up_loc[i][j]-1)*max(0, k-1);
				new_up_fin[i][j] = max(new_up_fin[i][j], old_up_fin[i][j]);
				new_up_fin[i][j] = max(new_up_fin[i][j], old_up_fin[i][j+1]);
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n-k; j++) {
				o = max(o, (long long)new_up_fin[i][j]*new_down_fin[i][j]);
				old_up_loc[i][j] = new_up_loc[i][j];
				old_up_fin[i][j] = new_up_fin[i][j];
				old_down_loc[i][j] = new_down_loc[i][j];
				old_down_fin[i][j] = new_down_fin[i][j];
			}
		}
	}
	if (o == 0) {
		fout << -1 << endl;
	} else {
		fout << o << endl;
	}
}