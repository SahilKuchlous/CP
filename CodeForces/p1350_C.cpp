#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	map<int, int> fact[2];
	for (int i=0; i<2; i++) {
		int cur = 2;
		while (a[i] > 1) {
			if (a[i]%cur != 0) {
				cur++;
				continue;
			}
			a[i] /= cur;
			fact[i][cur]++;
		}
	}
	map<int, int> freq1, freq2;
	freq1 = fact[0];
	for (auto i: fact[1]) {
		if (fact[1][i.first] > freq1[i.first]) {
			freq2[i.first] = freq1[i.first];
			freq1[i.first] = fact[1][i.first];
		} else {
			freq2[i.first] = fact[1][i.first];
		}
	}
	for (int i=2; i<n; i++) {
		for (auto j: freq1) {
			int f = 0;
			while (a[i]%j.first == 0) {
				a[i] /= j.first;
				f++;
			}
			if (f < freq2[j.first]) {
				freq1[j.first] = freq2[j.first];
				freq2[j.first] = f;
			} else if (f < freq1[j.first]) {
				freq1[j.first] = f;
			}
		}
	}
	long long o = 1;
	for (auto i: freq1) {
		o *= pow(i.first, i.second);
	}
	cout << o << endl;
}