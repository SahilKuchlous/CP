#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("sleepy.in");
ofstream fout("sleepy.out");
int fen[100100];
void add (int x) {
	for (int i=x+1; i<100100; i+=(i&-i)) {
		fen[i]++;
	}
}
int query (int x) {
	int s = 0;
	for (int i=x+1; i>0; i-=(i&-i)) {
		s += fen[i];
	}
	return s;
}
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int e = 0;
	for (int i=n-1; i>0; i--) {
		if (a[i] > a[i-1]) {
			add(a[i]);
		} else {
			add(a[i]);
			e = i;
			break;
		}
	}
	fout << e << endl;
	for (int i=0; i<e; i++) {
		fout << e-i-1+query(a[i]);
		add(a[i]);
		if (i<e-1) {
			fout << " ";
		}
	}
	fout << endl;
}