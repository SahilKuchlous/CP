// Chipotgang 618311

#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n = 52;
	string a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector<string> cur;
	for (int i=0; i<n; i++) {
		cur.push_back(a[i]);
		while (true) {
			bool done = true;
			for (int j=cur.size()-1; j>=3; j--) {
				if (cur[j][0] == cur[j-3][0]) {
					cur.erase(cur.begin()+j-3);
					cur.erase(cur.begin()+j-3);
					cur.erase(cur.begin()+j-3);
					cur.erase(cur.begin()+j-3);
					done = false;
					break;
				}
			}
			if (!done) continue;
			for (int j=cur.size()-1; j>=3; j--) {
				if (cur[j][1] == cur[j-3][1]) {
					cur.erase(cur.begin()+j);
					cur.erase(cur.begin()+j-3);
					done = false;
					break;
				}
			}
			if (done) break;
		}
	}
	cout << cur.size() << " ";
	for (auto i: cur) {
		cout << i << " ";
	}
	cout << endl;
}