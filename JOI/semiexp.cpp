#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m, k;
long long a, b, c;
long long t;
long long pos[3005];
long long o = 0;
vector<long long> opts;
int main () {
	cin >> n >> m >> k;
	cin >> a >> b >> c;
	cin >> t;
	for (int i=0; i<m; i++) {
		cin >> pos[i];
		pos[i]--;
	}
	for (int i=0; i<m-1; i++) {
		long long dist = pos[i]*b;
		if (dist > t) break;
		long long temp = min(pos[i+1]-pos[i], (t-dist)/a+1);
		o += max(0ll, temp);
		long long nxt = pos[i]+temp;
		dist += temp*c;
		for (int j=1; j<=k; j++) {
			if (nxt >= pos[i+1] || dist > t) break;
			long long temp = min(pos[i+1]-nxt, (t-dist)/a+1);
			opts.push_back(temp);
			nxt += temp;
			dist += temp*c;
		}
	}
	if ((n-1)*b <= t) o++;
	sort(opts.begin(), opts.end(), greater<long long>());
	for (int i=0; i<min((long long)opts.size(), k-m); i++) {
		o += opts[i];
	}
	cout << o-1 << endl;
}