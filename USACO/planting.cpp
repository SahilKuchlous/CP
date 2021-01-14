#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("planting.in");
ofstream fout("planting.out");
int main () {
	int n;
	fin >> n;
	int deg[n+1];
	for (int i=1; i<=n; i++) {
		deg[i] = 0;
	}
	int x, y;
	for (int i=0; i<n-1; i++) {
		fin >> x >> y;
		deg[x]++;
		deg[y]++;
	}
	int o = 0;
	for (int i=1; i<=n; i++) {
		o = max(o, deg[i]);
	}
	fout << o+1 << endl;
}