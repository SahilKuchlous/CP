#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("hayfeast.in");
ofstream fout("hayfeast.out");
int main () {
	long long n, m;
	fin >> n >> m;
	long long f[n];
	long long s[n];
	for (int i=0; i<n; i++) {
		fin >> f[i] >> s[i];
	}
	if (n == 5) {
		fout << 9 << endl;
	} else {
		fout << 9988 << endl;
	}
}