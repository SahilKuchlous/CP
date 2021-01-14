#include <iostream>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000000
long long pow2 (int x) {
	long long bin[30];
	bin[0] = 2;
	for (int i=1; i<30; i++) {
		bin[i] = (bin[i-1]*bin[i-1])%MOD;
	}
	long long o = 1;
	for (int i=0; i<30; i++) {
		if (x & (1ll<<i)) {
			o = (o*bin[i])%MOD;
		}
	}
	return o;
}
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	map< pair<int, int>, int > fixed;
	set< pair<int, int> > pts;
	int xi, yi, ti;
	for (int i=0; i<k; i++) {
		cin >> xi >> yi >> ti;
		pts.insert({xi, yi});
		fixed[{xi, yi}] = ti;
	}
	int cnt = 0;
	bool pos = true;
	for (auto i: pts) {
		if (pts.find({i.first-1, i.second}) != pts.end() && pts.find({i.first, i.second-1}) != pts.end() && pts.find({i.first-1, i.second-1}) != pts.end()) {
			int ttl = fixed[{i.first-1, i.second}]+fixed[{i.first, i.second-1}]+fixed[{i.first-1, i.second-1}]+fixed[i];
			if (ttl%2 == 0) {
				pos = false;
				break;
			}
		} else {
			cnt++;
		}
	}
	if (n+m-1 < cnt) {
		pos = false;
	}
	if (pos) {
		cout << pow2(n+m-1-cnt) << endl;
	} else {
		cout << 0 << endl;
	}
}