#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	int dir_x[n], dir_y[n];
	for (int i=0; i<n; i++) {
		cin >> dir_x[i] >> dir_y[i];
	}
	long long cur_x, cur_y;
	long long o = 0;
	for (int i=0; i<(1<<n); i++) {
		cur_x = cur_y = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				cur_x += dir_x[j];
				cur_y += dir_y[j];
			}
		}
		o = max(o, cur_x*cur_x + cur_y*cur_y);
	}
	cout << o << endl;
}