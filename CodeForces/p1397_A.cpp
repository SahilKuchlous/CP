#include <iostream>
using namespace std;
#define MAXN 1005
int n;
string a[MAXN];
int freq[26];
bool pos;
int main () {
	int t;
	cin >> t;
	while (t--) {
		for (int i=0; i<26; i++) {
			freq[i] = 0;
		}
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (auto j: a[i]) {
				freq[j-'a']++;
			}
		}
		pos = true;
		for (int i=0; i<26; i++) {
			if (freq[i]%n != 0) pos = false;
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}