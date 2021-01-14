#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main () {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int a1[n1], a2[n2], a3[n3];
	unordered_set<int> s;
	vector<int> v;
	for (int i=0; i<n1; i++) {
		cin >> a1[i];
		if (s.find(a1[i]) == s.end()) {
			s.insert(a1[i]);
		}
	}
	for (int i=0; i<n2; i++) {
		cin >> a2[i];
		if (s.find(a2[i]) == s.end()) {
			s.insert(a2[i]);
		} else {
			v.push_back(a2[i]);
			s.erase(a2[i]);
		}
	}
	for (int i=0; i<n3; i++) {
		cin >> a3[i];
		if (s.find(a3[i]) != s.end()) {
			v.push_back(a3[i]);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto i:v) {
		cout << i << endl;
	}
	return 0;
}