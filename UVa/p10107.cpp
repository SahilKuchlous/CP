#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
		if (v.size()%2 == 1) {
			nth_element(v.begin(), v.begin()+(v.size()-1)/2, v.end());
			cout << v[(v.size()-1)/2] << endl;
		} else {
			nth_element(v.begin(), v.begin()+v.size()/2, v.end());
			nth_element(v.begin(), v.begin()+v.size()/2-1, v.end());
			cout << (v[v.size()/2]+v[v.size()/2-1])/2 << endl;
		}
	}
}