#include <iostream>
using namespace std;
int main () {
	long long n;
	cin >> n;
	int cnt = 0;
	for (int i=2; i*i<=n; i++) {
		if (n == 1) break;
		if (n%i == 0) {
			n /= i;
			cnt++;
			i--;
		}
	}
	if (n > 1) cnt++;
	cout << cnt << endl;
}