#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("div7.in");
ofstream fout("div7.out");
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int pre[n+1];
	pre[0] = 0;
	for (int i=1; i<=n; i++) {
		pre[i] = (pre[i-1]+(a[i-1]%7))%7;
	}
	int f_occ[7];
	int l_occ[7];
	for (int i=0; i<7; i++) {
		f_occ[i] = 2*n;
		l_occ[i] = -1;
	}
	for (int i=0; i<=n; i++) {
		f_occ[pre[i]] = min(f_occ[pre[i]], i);
		l_occ[pre[i]] = max(l_occ[pre[i]], i);
	}
	int o = 0;
	for (int i=0; i<7; i++) {
		o = max(o, l_occ[i]-f_occ[i]);
	}
	fout << o << endl;
}