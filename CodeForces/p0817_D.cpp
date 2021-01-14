#include <iostream>
#include <stack>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	stack< pair<int, int> > low, high;
	low.push(make_pair(0, 0));
	high.push(make_pair(1e8, 0));
	long long lsum = 0, hsum = 0;
	pair<int, int> cur;
	int cnt;
	long long o = 0;
	for (int i=0; i<n; i++) {
		cnt = 1;
		while (true) {
			cur = low.top();
			if (cur.first >= a[i]) {
				cnt += cur.second;
				lsum -= 1ll*cur.first*cur.second;
				low.pop();
			} else {
				break;
			}
		}
		low.push(make_pair(a[i], cnt));
		lsum += 1ll*a[i]*cnt;
		cnt = 1;
		while (true) {
			cur = high.top();
			if (cur.first <= a[i]) {
				cnt += cur.second;
				hsum -= 1ll*cur.first*cur.second;
				high.pop();
			} else {
				break;
			}
		}
		high.push(make_pair(a[i], cnt));
		hsum += 1ll*a[i]*cnt;
		o += hsum-lsum;
	}
	cout << o << endl;
}