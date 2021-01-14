#include <iostream>
using namespace std;
#define int long long
signed main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool turn = true;
		int score = 0;
		while (n > 0) {
			int pts;
			if (n%4 == 0 && n > 8) {
				pts = 1;
			} else if (n%2 == 1) {
				pts = 1;
			} else {
				pts = n/2;
			}
			if (turn) score += pts;
			n -= pts;
			turn = !turn;
		}
		cout << score << endl;
	}
}