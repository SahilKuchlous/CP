#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("homework.in");
ofstream fout("homework.out");
int main () {
	int n;
	fin >> n;
	long long a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	long long sum[n];
	sum[0] = 0;
	long long m = a[n-1];
	for (int i=1; i<n; i++) {
		if (a[n-i-1] < m) {
			m = a[n-i-1];
			sum[i] = sum[i-1]+m;
		} else {
			sum[i] = sum[i-1]+a[n-i-1];
		}
	}
	/*
	for (int i=0; i<n; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
	*/
	vector<long long> o;
	long long best = 0;
	long long d = 1;
	for (int i=1; i<n-1; i++) {
		if (sum[i]*d > best*i) {
			best = sum[i];
			d = i;
			o.clear();
			o.push_back(n-i-1);
		} else if (sum[i]*d == best*i) {
			o.push_back(n-i-1);
		}
	}
	for (auto i: o) {
		fout << i << endl;
	}
}