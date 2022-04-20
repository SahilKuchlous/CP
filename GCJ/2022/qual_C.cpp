#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (cnt+1 <= a[i]) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}