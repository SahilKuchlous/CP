#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
ifstream fin("cowjog.in");
ofstream fout("cowjog.out");
int main () {
	long long n, t;
	fin >> n >> t;
	long long p, s;
	vector<long long> cur;
	for (int i=0; i<n; i++) {
		fin >> p >> s;
		long long x = -p-t*s;
		if (cur.size() == 0 || x >= cur.back()) {
			cur.push_back(x);
		} else {
			*upper_bound(cur.begin(), cur.end(), x) = x;
		}
	}
	fout << cur.size() << endl;
}