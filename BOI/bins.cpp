#include <iostream>
using namespace std;
int m, n;
int sz[20100];
int freq1[1001], freq2[1001];
int cur1[1001], cur2[1001];
int o = 0;
int main () {
	cin >> m >> n;
	for (int i=0; i<n; i++) {
		cin >> sz[i];
	}
	for (int i=0; i<n/2; i++) {
		freq1[sz[i]]++;
		freq2[sz[i]]--;
		freq2[sz[2*i]]++;
		freq2[sz[2*i+1]]++;
		for (int j=0; j<=m; j++) {
			cur1[j] = freq1[j];
			cur2[j] = freq2[j];
		}
		int pos1 = 0, pos2 = 0;
		bool valid = true;
		while (pos1 <= m || pos2 <= m) {
			if (pos1 <= m && cur1[pos1] == 0) {
				pos1++;
				continue;
			}
			if (pos2 <= m && cur2[pos2] == 0) {
				pos2++;
				continue;
			}
			if (pos1 >= pos2) {
				valid = false;
				break;
			}
			int red = min(cur1[pos1], cur2[pos2]);
			cur1[pos1] -= red;
			cur2[pos2] -= red;
		}
		if (valid) o = i+1;
	}
	cout << o << endl;
}