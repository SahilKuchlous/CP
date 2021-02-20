#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long inp;
	long long ttl = 0;
	for (int i=0; i<n; i++) {
		cin >> inp;
		ttl += inp;
	}
	cout << ttl << endl;
}