#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1000005

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> s;
	long long mx = 0;
	for (int i=0; i<n; i++) {
		long long inp;
		cin >> inp;
		s.push_back(inp);
		mx = max(mx, inp);
	}
	sort(s.begin(), s.end());

	long long cnt = 0;
	for (auto i: s) {
		for (long long j=i+1; j<MAXN; j++) {
			long long val = j*j-i*i;
			if (val > mx) {
				break;
			}
			int index = lower_bound(s.begin(), s.end(), val)-s.begin();
			if (index < n && s[index] == val) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}