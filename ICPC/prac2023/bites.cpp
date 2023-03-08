#include <iostream>
#include <string>
using namespace std;
int main () {
	int n;
	cin >> n;
	string inp;
	bool o = true;
	for (int i=1; i<=n; i++) {
		cin >> inp;
		if (inp[0] == 'm') continue;
		if (stoi(inp) == i) continue;
		o = false;
		break;
	}
	if (o) {
		cout << "makes sense" << endl;
	} else {
		cout << "something is fishy" << endl;
	}
}