#include "grader.h"
#include <iostream>
#include <cmath>
using namespace std;
bool check (int n, int pos[], long long b, int len) {
	long long total = 0;
	for (int i=0; i<len; i++) {
		total += abs(pos[i]-pos[len/2]);
	}
	if (total <= b) return true;
	for (int i=0; i<n-len; i++) {
		total -= pos[len/2+i]-pos[i];
		total += pos[i+len]-pos[len/2+i+1];
		if (len%2 == 0) total += pos[len/2+i+1]-pos[len/2+i];
		if (total <= b) return true;
	}
	return false;
}
int besthub (int n, int max_x, int pos[], long long b) {
	int o;
	int l = 1, r = n, m;
	while (l <= r) {
		m = (l+r)/2;
		bool ans = check(n, pos, b, m);
		if (ans) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	return o;
}