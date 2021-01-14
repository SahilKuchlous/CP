#include <iostream>
#include <set>
#include <string>
using namespace std;
int main () {
	int count = 0;
	while (true) {
		count++;
		int n, p;
		cin >> n >> p;
		if (n == 0 && p == 0) {
			break;
		}
		if (count > 1) {
			cout << endl;
		}
		cin >> ws;
		set<string> r;
		string in;
		for (int i=0; i<n; i++) {
			getline(cin, in);
			r.insert(in);
		}
		string op = "";
		int os = -1;
		double ob = 1000000001;
		for (int i=0; i<p; i++) {
			string name;
			double d;
			int rc;
			getline(cin, name);
			cin >> d >> rc;
			cin >> ws;
			for (int j=0; j<rc; j++) {
				getline(cin, in);
			}
			if (rc > os || (rc == os && d < ob)) {
				os = rc;
				ob = d;
				op = name;
			}
		}
		cout << "RFP #" << count << endl;
		cout << op << endl;
	}
}