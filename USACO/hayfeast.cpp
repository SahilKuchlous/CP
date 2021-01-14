#include <iostream>
#include <fstream>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;
ifstream fin("hayfeast.in");
ofstream fout("hayfeast.out");
int main () {
	long long n, m;
	fin >> n >> m;
	int f[n];
	int s[n];
	for (int i=0; i<n; i++) {
		fin >> f[i] >> s[i];
	}
	int back_i = 0;
	int front_i = 0;
	unsigned long long cur_sum = 0;
	long long best = 1e12;
	multiset< int, greater<int> > ms;
	while (true) {
		// fout << front_i << " " << back_i << " " << best << endl;
		if (cur_sum < m) {
			if (front_i >= n) {
				break;
			}
			cur_sum += f[front_i];
			ms.insert(s[front_i]);
			front_i++;
		} else {
			if (*ms.begin() < best) {
				best = *ms.begin();
			}
			cur_sum -= f[back_i];
			ms.erase(ms.find(s[back_i]));
			back_i++;
		}
	}
	fout << best << endl;
	fout.flush();
}