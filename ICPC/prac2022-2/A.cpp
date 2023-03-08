#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;
int main () {
	srand(time(NULL));

	int n;
	cin >> n;

	bool ans = true;
	int rep1, rep2, ttl;

	cout << "? " << n;
	for (int j=1; j<=n; j++) {
		cout << " " << j;
	}
	cout << endl;
	cin >> ttl;
	if (ttl%2 != 0) {
		ans = false;
	}

	for (int i=0; i<4; i++) {
		vector<int> mask;
		int cnt = 0;
		for (int j=0; j<n; j++) {
			mask.push_back(rand()%2);
			if (mask[j] == 1) {
				cnt++;
			}
		}

		cout << "? " << cnt;
		for (int j=0; j<n; j++) {
			if (mask[j] == 1) {
				cout << " " << j+1;
			}
		}
		cout << endl;
		cin >> rep1;
		
		cout << "? " << n-cnt;
		for (int j=0; j<n; j++) {
			if (mask[j] == 0) {
				cout << " " << j+1;
			}
		}
		cout << endl;
		cin >> rep2;

		int cut = ttl-rep1-rep2;
		if (cut%2 != 0) {
			ans = false;
		}
	}

	if (ans) {
		cout << "! YES" << endl;
	} else {
		cout << "! NO" << endl;
	}
}