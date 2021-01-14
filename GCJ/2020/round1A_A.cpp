#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=1; z<=t; z++) {
		int n;
		cin >> n;
		string a[n];
		int pre[n];
		int post[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (int j=0; j<a[i].length(); j++) {
				if (a[i].at(j) == '*') {
					pre[i] = j;
					break;
				}
			}
			for (int j=a[i].length()-1; j>=0; j--) {
				if (a[i].at(j) == '*') {
					post[i] = j;
					break;
				}
			}
		}
		string o1, o2, o3;
		o1 = a[0].substr(0, pre[0]);
		o3 = a[0].substr(post[0]+1);
		for (int i=pre[0]; i<post[0]; i++) {
			if (a[0][i] != '*') o2 += a[0][i];
		}
		bool pos = true;
		for (int i=1; i<n; i++) {
			for (int j=0; j<min((int)o1.size(), pre[i]); j++) {
				if (a[i][j] != o1[j]) {
					pos = false;
					break;
				}
			}
			if (o1.size() < pre[i]) {
				o1 = a[i].substr(0, pre[i]);
			}
			for (int j=0; j<min(o3.size(), a[i].length()-post[i]-1); j++) {
				if (a[i][a[i].length()-j-1] != o3[o3.length()-j-1]) {
					pos = false;
					break;
				}
			}
			if (!pos) break;
			if (o3.size() < a[i].length()-post[i]-1) {
				o3 = a[i].substr(post[i]+1);
			}
			for (int j=pre[i]; j<post[i]; j++) {
				if (a[i][j] != '*') {
					o2 += a[i][j];
				}
			}
		}
		cout << "Case #" << z << ": ";
		if (pos) {
			cout << o1+o2+o3 << endl;
		} else {
			cout << '*' << endl;
		}
	}
}