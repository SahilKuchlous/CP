#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		set<int> done;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				done.insert(a[j]-a[i]);
			}
		}
		cout << done.size() << endl;
	}
}