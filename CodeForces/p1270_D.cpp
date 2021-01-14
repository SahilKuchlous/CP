#include <iostream>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	int max_val = -1, max_freq = 0;
	int x, y;
	for (int i=1; i<=k+1; i++) {
		cout << "? ";
		for (int j=1; j<=k+1; j++) {
			if (j != i) {
				cout << j << " ";
			}
		}
		cout << endl;
		cout.flush();
		cin >> y >> x;
		if (x == max_val) {
			max_freq++;
		} else if (x > max_val) {
			max_val = x;
			max_freq = 1;
		}
	}
	cout << "! " << max_freq << endl;
}