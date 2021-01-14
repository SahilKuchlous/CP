#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("maxcross.in");
ofstream fout("maxcross.out");
int n, k, b;
int a[100100];
bool test (int size) {
	for (int i=0; i<=b-size; i++) {
		if (a[i+size+1]-a[i]-1 >= k) {
			return true;
		}
	}
	return false;
}
int main () {
	fin >> n >> k >> b;
	a[0] = 0;
	for (int i=1; i<=b; i++) {
		fin >> a[i];
	}
	a[b+1] = n+1;
	sort(a, a+b+2);
	int low = 0, high = b, mid;
	int o = 100100;
	while (low <= high) {
		mid = (low+high)/2;
		if (test(mid)) {
			o = mid;
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	fout << o << endl;
}