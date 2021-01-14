#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	char a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i=0; i<n; i++) {
		bool org = true;
		for (int j=0; j<i; j++) {
			if (a[i] == a[j] || a[i] == a[j]+32 || a[i] == a[j]-32) {
				org = false;
			}
		}
		if (org) cnt++;
	}
	cout << (cnt==26 ? "YES":"NO") << endl;
}