#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> o;
		int cur = 1;
		while (n > 0) {
			n -= cur;
			if (n - 2*cur >= 2*cur) {
				o.push_back(cur);
				cur *= 2;
			} else {
				if (n <= 2*cur) {
					o.push_back(n-cur);
				} else {
					o.push_back(n/2-cur);
					o.push_back(n%2==0 ? 0:1);
				}
				break;
			}
		}
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i << " ";
		}
		cout << endl;
	}
}