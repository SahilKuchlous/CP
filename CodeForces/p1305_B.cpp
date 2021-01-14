#include <iostream>
#include <string>
#include <set>
using namespace std;
int main () {
	string s;
	cin >> s;
	set<int> opp;
	bool front = true;
	int p1 = 0, p2 = s.length()-1;
	while (true) {
		if (front) {
			while (p1 <= p2 && s.at(p1) == ')') {
				p1++;
			}
			if (p1 > p2) break;
			opp.insert(p1+1);
			p1++;
			front = false;
		} else {
			while (p1 <= p2 && s.at(p2) == '(') {
				p2--;
			}
			if (p1 > p2) {
				opp.erase(p1);
				break;
			}
			opp.insert(p2+1);
			p2--;
			front = true;
		}
	}
	if (opp.size() == 0) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
		cout << opp.size() << endl;
		for (auto i: opp) {
			cout << i << " ";
		}
		cout << endl;
	}
}