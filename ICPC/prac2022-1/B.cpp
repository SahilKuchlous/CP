#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	char a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int cur_l = 0;
	int o = 0;
	for (int i=0; i<n; i++) {
		if (a[i] == 'a') {
			cur_l++;
		} else {
			if (cur_l > 1) o += cur_l;
			cur_l = 0;
		}
	}
	if (cur_l > 1) o += cur_l;
	cout << o << endl;
}