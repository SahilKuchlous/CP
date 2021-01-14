#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");
int main () {
	int k, n;
	fin >> k >> n;
	int a[n+1][k];
	int x;
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++) {
			fin >> x;
			a[x][i] = j;
		}
	}
	int o = 0;
	bool p = true;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			p = true;
			for (int z=0; z<k; z++) {
				if (a[i][z] <= a[j][z]) {
					p = false;
					break;
				}
			}
			if (p) {
				o++;
			}
		}
	}
	fout << o << endl;
}