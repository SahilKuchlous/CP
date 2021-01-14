#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a[n];
		int c[10];
		for (int i=0; i<10; i++) {
			c[i] = 0;
		}
		for (int i=0; i<n; i++) {
			cin >> a[i];
			c[a[i][3]-'0']++;
		}
		int o = 0;
		bool done = false;
		while (!done) {
			done = true;
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					if (a[i] == a[j]) {
						o++;
						done = false;
						for (int k=0; k<10; k++) {
							if (c[k] == 0) {
								c[k]++;
								c[a[i][3]-'0']--;
								a[i] = a[i].substr(0, 3);
								a[i]+=to_string(k);
								break;
							}
						}
					}
				}
			}
		}
		cout << o << endl;
		for (int i=0; i<n; i++) {
			cout << a[i] << endl;
		}
	}
}