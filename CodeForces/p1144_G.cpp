#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	pair<int, int> dp_inc[n+1];
	pair<int, int> dp_dec[n+1];
	bool prev_inc[n+1];
	bool prev_dec[n+1];
	dp_inc[0] = dp_dec[0] = make_pair(-1, 1e6);
	for (int i=1; i<=n; i++) {
		dp_inc[i] = make_pair(1e6, -1);
		if (dp_inc[i-1].first < a[i-1] && dp_inc[i-1].second > dp_inc[i].second) {
			dp_inc[i] = make_pair(a[i-1], dp_inc[i-1].second);
			prev_inc[i] = true;
		}
		if (dp_dec[i-1].first < a[i-1] && dp_dec[i-1].second > dp_inc[i].second) {
			dp_inc[i] = make_pair(a[i-1], dp_dec[i-1].second);
			prev_inc[i] = false;
		}
		dp_dec[i] = make_pair(1e6, -1);
		if (dp_inc[i-1].second > a[i-1] && dp_inc[i-1].first < dp_dec[i].first) {
			dp_dec[i] = make_pair(dp_inc[i-1].first, a[i-1]);
			prev_dec[i] = true;
		}
		if (dp_dec[i-1].second > a[i-1] && dp_dec[i-1].first < dp_dec[i].first) {
			dp_dec[i] = make_pair(dp_dec[i-1].first, a[i-1]);
			prev_dec[i] = false;
		}
	}
	/*
	for (int i=0; i<=n; i++) {
		cout << dp_inc[i].first << " " << dp_inc[i].second << "; " << dp_dec[i].first << " " << dp_dec[i].second << endl;
		cout << prev_inc[i] << " " << prev_dec[i] << endl;
	}
	*/
	int ans[n];
	if (dp_inc[n] != make_pair((int)1e6, -1)) {
		cout << "YES" << endl;
		bool cur = true;
		for (int i=n; i>0; i--) {
			ans[i-1] = !cur;
			if (cur) {
				cur = prev_inc[i];
			} else {
				cur = prev_dec[i];
			}
		}
		for (int i=0; i<n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	} else if (dp_dec[n] != make_pair((int)1e6, -1)) {
		cout << "YES" << endl;
		bool cur = false;
		for (int i=n; i>0; i--) {
			ans[i-1] = !cur;
			if (cur) {
				cur = prev_inc[i];
			} else {
				cur = prev_dec[i];
			}
		}
		for (int i=0; i<n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}