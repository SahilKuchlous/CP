#include <iostream>
#define MAXN 200005
using namespace std;
int psum[MAXN][20];

int main () {
	for (int i=0; i<MAXN-1; i++) {
		for (int j=0; j<20; j++) {
			psum[i+1][j] = psum[i][j];
			if ((i & (1<<j)) == 0) {
				psum[i+1][j]++;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		int o = MAXN;
		for (int i=0; i<20; i++) {
			o = min(o, psum[r+1][i]-psum[l][i]);
		}
		cout << o << endl;
	}
