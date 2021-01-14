#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("diamond.in");
ofstream fout("diamond.out");
int main () {
	int n, k;
	fin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	sort(a, a+n);
	int front = 0, back = 0;
	int dp_start[n];
	int dp_end[n];
	while (back < n) {
		if (front < n && a[front]-a[back] <= k) {
			dp_end[front] = front-back+1;
			front++;
		} else {
			dp_start[back] = front-back;
			back++;
		}
	}
	for (int i=1; i<n; i++) {
		dp_end[i] = max(dp_end[i], dp_end[i-1]);
	}
	for (int i=n-2; i>=0; i--) {
		dp_start[i] = max(dp_start[i], dp_start[i+1]);
	}
	int o = 0;
	for (int i=0; i<n-1; i++) {
		o = max(o, dp_end[i]+dp_start[i+1]);
	}
	fout << o << endl;
}