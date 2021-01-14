#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n >> l;
		vector<int> v;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			v.push_back(inp);
		}
		cout << floor(float((n-1)/(l-1))) << endl;
	}
}