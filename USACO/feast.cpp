#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("feast.in");
ofstream fout("feast.out");
int main () {
	int t, a, b;
	fin >> t >> a >> b;
	bool dp1[t+1];
	bool dp2[t+1];
	dp1[0] = dp2[0] = true;
	for (int i=1; i<=t; i++) {
		dp1[i] = dp2[i] = false;
		if (i-a >= 0 && dp1[i-a]) {
			dp1[i] = true;
			dp2[i/2] = true;
		}
		if (i-b >= 0 && dp2[i-b]) {
			dp1[i] = true;
			dp2[i/2] = true;
		}
	}
	for (int i=1; i<=t; i++) {
		if (i-a >= 0 && dp2[i-a]) {
			dp2[i] = true;
		}
		if (i-b >= 0 && dp2[i-b]) {
			dp2[i] = true;
		}
	}
	for (int i=t; i>=0; i--) {
		if (dp1[i] || dp2[i]) {
			fout << i << endl;
			break;
		}
	}
}