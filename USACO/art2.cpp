#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("art2.in");
ofstream fout("art2.out");
int main () {
	int n;
	fin >> n;
	int a[n+2];
	a[0] = a[n+1] = 0;
	for (int i=1; i<=n; i++) {
		fin >> a[i];
	}
	int start[n+3], end[n+3];
	for (int i=0; i<=n; i++) {
		start[i] = 1e6;
		end[i] = -1e6;
	}
	for (int i=0; i<=n+1; i++) {
		start[a[i]] = min(start[a[i]], i);
		end[a[i]] = max(end[a[i]], i);
	}
	stack<int> cur;
	int d = 0;
	int max_d = 0;
	bool pos = true;
	for (int i=0; i<=n+1; i++) {
		if (start[a[i]] == i) {
			cur.push(a[i]);
			d++;
			max_d = max(d, max_d);
		}
		if (a[i] != cur.top()) {
			pos = false;
			break;
		}
		if (end[a[i]] == i) {
			cur.pop();
			d--;
		}	
	}
	if (pos) {
		fout << max_d-1 << endl;
	} else {
		fout << -1 << endl;
	}
}