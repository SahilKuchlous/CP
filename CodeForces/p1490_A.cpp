#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			v.push_back(inp);
		}
		int o = 0;
		for (int i=0; i<v.size()-1; i++) {
			if (2*v[i] < v[i+1]) {
				v.insert(v.begin()+i+1, 2*v[i]);
				o++;
			}
			if (v[i] > 2*v[i+1]) {
				v.insert(v.begin()+i+1, (v[i]+1)/2);
				o++;
			}
		}
		cout << o << endl;
	}
}