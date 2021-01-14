#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int x, y, z;
	cin >> x >> y >> z;
	long long a1[x], a2[y], a3[z];
	long long sum = 0;
	long long s1 = 0, s2 = 0, s3 = 0, m1 = 1e10, m2 = 1e10, m3 = 1e10;
	for (int i=0; i<x; i++) {
		cin >> a1[i];
		s1 += a1[i];
		m1 = min(m1, a1[i]);
	}
	for (int i=0; i<y; i++) {
		cin >> a2[i];
		s2 += a2[i];
		m2 = min(m2, a2[i]);
	}
	for (int i=0; i<z; i++) {
		cin >> a3[i];
		s3 += a3[i];
		m3 = min(m3, a3[i]);
	}
	cout << s1+s2+s3 - 2*min(min(s1, min(s2, s3)), m1+m2+m3-max(m1, max(m2, m3))) << endl;
}