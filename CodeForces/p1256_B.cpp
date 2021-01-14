#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int x = 0;
		while (x < n) {
			int m = 1000;
			int mi = -1;
			for (int i=x; i<n; i++) {
				if (a[i] < m) {
					m = a[i];
					mi = i;
				}
			}
			if (mi == x) {
				x++;
				continue;
			} 
			int l = a[mi];
			a.erase(a.begin()+mi);
			a.insert(a.begin()+x, l);
			x = mi;
		}
		for (int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl; 
	}
}