#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("snowboots.in");
ofstream fout("snowboots.out");
int main () {
	int n, b;
	cin >> n >> b;
	int snow[n];
	for (int i=0; i<n; i++) {
		cin >> snow[i];
	}
	pair<int, int> boots[b];
	for (int i=0; i<b; i++) {
		cin >> boots[i].first >> boots[i].second;
	}
	int boot_i = 0;
}
