#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("herding.in");
ofstream fout("herding.out");
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	sort(a, a+n);
	int m = 0;
	int c = 0;
	for (int i=0; i<n; i++) {
		while (a[c] < a[i]+n && c<n) {
			c++;
		}
		if (c-i > m) {
			m = c-i;
		}
	}
	fout << n-m << endl << max(a[n-1]-a[1]-n+2, a[n-2]-a[0]-n+2) << endl;
}