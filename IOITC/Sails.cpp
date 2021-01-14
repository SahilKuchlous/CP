#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<int, int> h[n];
	int k[n];
	int mh = 0;
	for (int i=0; i<n; i++) {
		cin >> h[i].first >> k[i];
		h[i].second = i;
		if (h[i].first > mh) {
			mh = h[i].first;
		}
	}
	sort(h, h+n);
}