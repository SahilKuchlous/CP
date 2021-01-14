#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		int presum[n+1];
		presum[0] = 0;
		for (int i=1; i<=n; i++) {
			presum[i] = presum[i-1]+(s.at(i-1)-'0');
		}
		int o = n;
		for (int i=0; i<=n; i++) {
			o = min(o, min(presum[i]+n-i-(presum[n]-presum[i]), i-presum[i]+presum[n]-presum[i]));
		}
		cout << o << endl;
	}
}