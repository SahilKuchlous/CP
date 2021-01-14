#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		vector<int> v;
		int x;
		for (int i=0; i<3; i++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cout << "Case " << z << ": " << v[1] << endl;
	}
}