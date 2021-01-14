#include <iostream>
#include <string>
using namespace std;
int main () {
	string s;
	cin >> s;
	int n = s.length();
	int m;
	cin >> m;
	int ai, bi, ci;
	string ns;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--;
		bi--;
		ci %= bi-ai+1;
		ns = "";
		ns += s.substr(0, ai);
		ns += s.substr(bi-ci+1, ci) + s.substr(ai, bi-ai-ci+1);
		if (bi < n-1) ns += s.substr(bi+1, n-bi-1);
		s = ns;
	}
	cout << s << endl;
}