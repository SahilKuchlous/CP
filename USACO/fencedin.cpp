#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("fencedin.in");
ofstream fout("fencedin.out");
int main () {
	int a, b, n, m;
	fin >> a >> b >> n >> m;
	int fx[n+2];
	for (int i=0; i<n; i++) {
		fin >> fx[i];
	}
	fx[n] = 0;
	fx[n+1] = a;
	sort(fx, fx+n+2);
	int fy[m+2];
	for (int i=0; i<m; i++) {
		fin >> fy[i];
	}
	fy[m] = 0;
	fy[m+1] = b;
	sort(fy, fy+m+2);
	int xint[n+1];
	for (int i=0; i<n+1; i++) {
		xint[i] = fx[i+1]-fx[i];
	}
	sort(xint, xint+n+1);
	int yint[m+1];
	for (int i=0; i<m+1; i++) {
		yint[i] = fy[i+1]-fy[i];
	}
	sort(yint, yint+m+1);
	int xc = 1, yc = 1;
	long long o = 1ll*xint[0]*m+1ll*yint[0]*n;
	while (xc < n+1 && yc < m+1) {
		if (xc == n+1) {
			o += yint[yc]*(n+1-xc);
			yc++;
			continue;
		}
		if (yc == m+1) {
			o += xint[xc]*(m+1-yc);
			xc++;
			continue;
		}
		if (xint[xc] < yint[yc]) {
			o += xint[xc]*(m+1-yc);
			xc++;
		} else {
			o += yint[yc]*(n+1-xc);
			yc++;
		}
	}
	fout << o << endl;
}