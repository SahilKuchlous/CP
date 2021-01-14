#include <iostream>
#include <string>
using namespace std;
int main () {
	string s;
	cin >> s;
	long long dp[26][26];
	long long freq[26];
	for (int i=0; i<26; i++) {
		freq[i] = 0;
		for (int j=0; j<26; j++) {
			dp[i][j] = 0;
		}
	}
	long long o = 0;
	for (auto i: s) {
		for (int j=0; j<26; j++) {
			dp[j][i-'a'] += freq[j];
			o = max(o, dp[j][i-'a']);
		}
		freq[i-'a']++;
		o = max(o, freq[i-'a']);
	}
	cout << o << endl;
}