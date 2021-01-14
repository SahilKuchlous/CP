#include <iostream>
#include <set>
using namespace std;
int n;
int a[500000];
int sum[2000000];
multiset<int> best;
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<(n+1)/2; i++) {
		sum[0] += a[i];
	}
	for (int i=1; i<3*n; i++) {
		sum[i] = sum[i-1]-a[(n+i-1)%n]+a[(i+(n-1)/2)%n];
	}
	for (int i=0; i<(n+1)/2; i++) {
		best.insert(sum[n-i]);
	}
	o = max(o, *best.begin());
	for (int i=n+1; i<2*n; i++) {
		best.erase(best.find(sum[i-((n+1)/2)]));
		best.insert(sum[i]);
		o = max(o, *best.begin());
	}
	cout << o << endl;
}