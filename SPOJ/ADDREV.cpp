#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	unsigned long n, a, b;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		cin >> b;
		string as = to_string(a);
		string bs = to_string(b);
		reverse(as.begin(), as.end());
		reverse(bs.begin(), bs.end());
		a = stoi(as);
		b = stoi(bs);
		unsigned long s = a+b;
		string ss = to_string(s);
		reverse(ss.begin(), ss.end());
		cout << stoi(ss) << endl;
	}
	return 0;
}