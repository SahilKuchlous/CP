#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("cardgame.in");
ofstream fout("cardgame.out");
int main () {
	int n;
	fin >> n;
	set<int> opp_c;
	int opp1[n/2];
	for (int i=0; i<n/2; i++) {
		fin >> opp1[i];
		opp_c.insert(opp1[i]);
	}
	int opp2[n/2];
	for (int i=0; i<n/2; i++) {
		fin >> opp2[i];
		opp_c.insert(opp2[i]);
	}
	set<int> my_c;
	for (int i=1; i<=2*n; i++) {
		if (opp_c.find(i) == opp_c.end()) {
			my_c.insert(i);
		}
	}
	int o = 0;
	sort(opp1, opp1+n/2, greater<int>());
	sort(opp2, opp2+n/2);
	for (int i=0; i<n/2; i++) {
		if (opp1[i] < *prev(my_c.end())) {
			my_c.erase(prev(my_c.end()));
			o++;
		}
		if (opp2[i] > *my_c.begin()) {
			my_c.erase(my_c.begin());
			o++;
		}
	}
	fout << o << endl;
}