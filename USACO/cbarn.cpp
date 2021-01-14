#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("cbarn.in");
ofstream fout("cbarn.out");
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int pos[n];
	int c = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<a[i]; j++) {
			pos[c] = i;
			c++;
		}
	}
	long long o = 1e13;
	for (int i=0; i<n; i++) {
		long long cur = 0;
		for (int j=0; j<n; j++) {
			if (j < pos[(i+j)%n]) {
				cur += pow(n-pos[(i+j)%n]+j, 2);
			} else {
				cur += pow(j-pos[(i+j)%n], 2);
			}
			// cout << cur << " ";
		}
		// cout << endl;
		o = min(o, cur);
	}
	fout << o << endl;
}