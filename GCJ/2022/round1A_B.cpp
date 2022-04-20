#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> opts1, opts2;
		long long ttl_pow = 0;
		long long test1 = 0;
		int cnt = 0;
		for (int i=0; (1ll<<i) <= 1000000000; i++) {
			if (i == n) {
				break;
			}
			cout << (1<<i) << " ";
			opts1.insert(1<<i);
			ttl_pow += (1<<i);
			test1 += (1<<i);
			cnt++;
		}
		int cur = 1;
		for (int i=cnt; i<n; i++) {
			while (opts1.find(cur) != opts1.end()) {
				cur++;
			}
			opts2.insert(cur);
			cout << cur << " ";
			test1 += cur;
			cur++;
		}
		cout << endl;
		int inp[n];
		for (int i=0; i<n; i++) {
			cin >> inp[i];
			test1 += inp[i];
		}
		sort(inp, inp+n);
		long long ttl1 = 0, ttl2 = 0;
		set<int> o1, o2;
		for (int i=n-1; i>=0; i--) {
			if (ttl1 <= ttl2) {
				ttl1 += inp[i];
				o1.insert(inp[i]);
			} else {
				ttl2 += inp[i];
				o2.insert(inp[i]);
			}
		}
		for (auto i: opts2) {
			if (ttl1 <= ttl2) {
				o1.insert(i);
				ttl1 += i;
			} else {
				o2.insert(i);
				ttl2 += i;
			}
		}
		if (ttl1 > ttl2) {
			swap(ttl1, ttl2);
			o1.swap(o2);
		}
		long long diff = ttl2-ttl1;
		long long expected = diff/2 + ttl_pow/2 + 1;
		for (auto i: opts1) {
			if (i & expected) {
				o1.insert(i);
			}
		}
		long long test2 = 0;
		for (auto i: o1) {
			cout << i << " ";
			test2 += i;
		}
		cout << endl;
	}
}