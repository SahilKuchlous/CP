#include <iostream>
#include <set>
#include <cmath>
#include <map>
using namespace std;

int n, m;
map<int, int> memo;

long long pow_2 (int x) {
	int r = 1;
	for (int i=0; i<x; i++) {
		r = (2*r)%m;
	}
	return r;
}

long long ans (int x) {
	if (x == 1) {
		return 2;
	}
	if (memo.find(x) != memo.end()) {
		return memo[x];
	}
	set<int> factors;
	for (int i=1; i<=ceil(sqrt(x*1.0)); i++) {
		if (x%i == 0) {
			factors.insert(i);
			factors.insert(x/i);
		}
	}
	factors.erase(x);
	long long r = pow_2(x);
	for (auto i: factors) {
		r = m + ((r-ans(i))%m);
	}
	memo[x] = r;
	return r;
}

int main () {
	cin >> n >> m;
	cout << ans(n)%m << endl;
}