#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
string s;
multiset<char> rem;
stack<char> cur;
vector<char> o;
int main () {
	cin >> s;
	for (auto i: s) {
		rem.insert(i);
	}
	for (auto i: s) {
		rem.erase(rem.find(i));
		cur.push(i);
		while (cur.size() > 0 && (rem.size() == 0 || cur.top() <= *rem.begin())) {
			o.push_back(cur.top());
			cur.pop();
		}
	}
	for (auto i: o) {
		cout << i;
	}
	cout << endl;
}