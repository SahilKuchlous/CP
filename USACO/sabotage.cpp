#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("sabotage.in");
ofstream fout("sabotage.out");
int round3 (double x) { return (int)(1000.0 * x + 0.5); }
int n;
double a[100100];
bool check (double m) {
	double total = 0;
	for (int i=0; i<n; i++) {
		total += a[i]-m;
	}
	double cur;
	double best;
	cur = best = a[1]-m;
	for (int i=2; i<n-1; i++) {
		if (cur < 0) cur = 0;
		cur += a[i]-m;
		best = max(best, cur);
	}
	return best > total;
}
int main () {
	fin >> n;
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	double h = 1e9, l = 1, m;
	while (round3(h) != round3(l)) {
		m = (h+l)/2;
		if (check(m)) {
			h = m;
		} else {
			l = m;
		}
	}
	fout << fixed << setprecision(3) << l << endl;
}