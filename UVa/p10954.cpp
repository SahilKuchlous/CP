#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int x;
		priority_queue< long long, vector<long long>, greater<long long> > p;
		for (int i=0; i<n; i++) {
			cin >> x;
			p.push(x);
		}
		long long o = 0;
		long long a, b;
		while (p.size() > 1) {
			a = p.top();
			p.pop();
			b = p.top();
			p.pop();
			o += a+b;
			p.push(a+b);
		}
		cout << o << endl;
	}
}