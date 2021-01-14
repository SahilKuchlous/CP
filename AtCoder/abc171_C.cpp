#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	long long n;
	cin >> n;
	string o = "";
	while (n > 0) {
		n--;
		o += 'a'+(n%26);
		n /= 26;
	}
	reverse(o.begin(), o.end());
	cout << o << endl;
}