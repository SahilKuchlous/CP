#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		string s;
		cin >> s;
		s = s+"0";
		string o = "";
		int depth = 0;
		for (int i=0; i<s.length(); i++) {
			while (depth != s.at(i)-'0') {
				if (depth < s.at(i)-'0') {
					o += "(";
					depth++;
				} else {
					o += ")";
					depth--;
				}
			}
			o += s.at(i);
		}
		cout << "Case #" << z+1 << ": " << o.substr(0, o.length()-1) << endl;
	}
}