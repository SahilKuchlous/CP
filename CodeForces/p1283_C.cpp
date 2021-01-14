#include <iostream>
#include <set>
using namespace std;
int main () {
	int n;
	cin >> n;
	set<int> give;
	set<int> get;
	set<int> done;
	int first = 0;
	int x;
	int a[n+1];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			give.insert(i);
			if (first == 0) {
				first = i;
			}
		}
		done.insert(a[i]);
	}
	for (int i=1; i<=n; i++) {
		if (done.find(i) == done.end()) {
			get.insert(i);
		}
	}
	for (auto i: give) {
		if (get.size() == 1 && *get.begin() == i) {
			int temp = a[first];
			a[first] = i;
			a[i] = temp;
			break;
		}
		for (auto j: get) {
			if (i != j) {
				a[i] = j;
				get.erase(j);
				break;
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}