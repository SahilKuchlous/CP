#include <iostream>
#include <set>
using namespace std;
bool used[1000100];
int main () {
	int n;
	cin >> n;
	int a[n+1];
	a[0] = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		used[a[i]] = true;
	}
	int o[n+1];
	int cur = 0;
	bool pos = true;
	for (int i=1; i<=n; i++) {
		if (a[i] != a[i-1]) {
			o[i] = a[i-1];
			used[a[i-1]] = true;
		} else {
			while (used[cur]) {
				cur++;
			}
			o[i] = cur;
			cur++;
		}
	}
	for (int i=1; i<=n; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}