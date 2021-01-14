#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 100005
int cnt[MAXN];
vector< pair<long long, long long> > ord;
long long o[MAXN];
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long inp;
		cin >> inp;
		long long n = inp;
		long long f = 2;
		for (int i=0; i<MAXN; i++) cnt[i] = 0;
		while (n > 1) {
			if (n%f == 0) {
				n /= f;
				cnt[f]++;
			} else {
				f++;
			}
			if (f*f > inp) break;
		}
		ord.clear();
		for (int i=2; i<MAXN; i++) {
			if (cnt[i] > 0) {
				ord.push_back(make_pair(-cnt[i], i));
			}
		}
		if (n > 1) {
			ord.push_back(make_pair(-1, n));
		}
		sort(ord.begin(), ord.end());
		int k = -(ord[0].first);
		int ind = 0;
		long long cur = 1;
		for (int i=k; i>0; i--) {
			while (ind < ord.size() && -ord[ind].first == i) {
				cur *= 1ll*ord[ind].second;
				ind++;
			}
			o[k-i] = cur;
		}
		cout << k << endl;
		for (int i=0; i<k; i++) {
			cout << o[i] << " ";
		}
		cout << endl;
	}
}