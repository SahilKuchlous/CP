#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
ifstream fin("cardgame.in");
ofstream fout("cardgame.out");
int main () {
	int n;
	fin >> n;
	int opn[n];
	set<int> done;
	for (int i=0; i<n; i++) {
		fin >> opn[i];
		done.insert(opn[i]);
	}
	set<int> plr1;
	set<int> plr2;
	for (int i=1; i<=2*n; i++) {
		if (done.find(i) == done.end()) {
			plr1.insert(i);
			plr2.insert(i);
		}
	}
	int pre[n+1];
	pre[0] = 0;
	for (int i=1; i<=n; i++) {
		pre[i] = pre[i-1];
		if (plr1.upper_bound(opn[i-1]) != plr1.end()) {
			plr1.erase(plr1.upper_bound(opn[i-1]));
			pre[i]++;
		}
	}
	int post[n+1];
	post[n] = 0;
	for (int i=n-1; i>=0; i--) {
		post[i] = post[i+1];
		if (plr2.upper_bound(opn[i]) != plr2.begin()) {
			plr2.erase(prev(plr2.upper_bound(opn[i])));
			post[i]++;
		}
	}
	int o = 0;
	for (int i=0; i<=n; i++) {
		o = max(o, pre[i]+post[i]);
	}
	fout << o << endl;
}