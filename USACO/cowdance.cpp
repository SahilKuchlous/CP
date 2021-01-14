#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("cowdance.in");
ofstream fout("cowdance.out");
int n, t;
int a[10100];
int check (int size) {
	multiset<long long> s;
	for (int i=0; i<size; i++) {
		s.insert(a[i]);
	}
	long long cur_t;
	int cur_i = size;
	while (cur_i < n) {
		cur_t = *s.begin();
		s.erase(s.begin());
		s.insert(a[cur_i]+cur_t);
		cur_i++;
	}
	return *--s.end();
}
int main () {
	fin >> n >> t;
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int low = 1, up = n, mid;
	int best = n+1;
	while (low <= up) {
		mid = (low+up)/2;
		if (check(mid) <= t) {
			best = mid;
			up = mid-1;
		} else {
			low = mid+1;
		}
	}
	fout << best << endl;
}