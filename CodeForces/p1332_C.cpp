#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int freq[k][26];
		for (int i=0; i<k; i++) {
			for (int j=0; j<26; j++) {
				freq[i][j] = 0;
			}
		}
		for (int i=0; i<n; i++) {
			freq[i%k][s.at(i)-'a']++;
		}
		int o = 0;
		int best;
		for (int i=0; i<k/2; i++) {
			best = 0;
			for (int j=0; j<26; j++) {
				best = max(best, freq[i][j]+freq[k-i-1][j]);
			}
			o += 2*n/k - best;
		}
		if (k%2 == 1) {
			best = 0;
			for (int i=0; i<26; i++) {
				best = max(best, freq[k/2][i]);
			}
			o += n/k-best;
		}
		cout << o << endl;
	}
}