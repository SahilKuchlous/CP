#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 100005
string s1, s2;
int freq1[26], freq2[26];
string pre, suf;
int main () {
	int t;
	cin >> t;
	while (t--) {
		for (int i=0; i<26; i++) {
			freq1[i] = freq2[i] = 0;
		}
		pre = suf = "";
		cin >> s1 >> s2;
		for (auto i: s2) {
			freq2[i-'a']++;
		}
		bool high = true;
		for (int i=1; i<s2.length(); i++) {
			if (s2[i] > s2[i-1]) {
				high = false;
				break;
			} else if (s2[i] < s2[i-1]) {
				break;
			}
		}
		sort(s1.begin(), s1.end());
		for (auto i: s1) {
			if (freq1[i-'a'] < freq2[i-'a']) {
				freq1[i-'a']++;
			} else {
				if (i < s2[0]) {
					pre += i;
				} else if (i > s2[0]) {
					suf += i;
				} else {
					if (high) {
						suf += i;
					} else {
						pre += i;
					}
				}
			}
		}
		cout << pre << s2 << suf << endl;
	}
}