#include <iostream>
#include <map>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<int, int> pos[n];
	for (int i=0; i<n; i++) {
		cin >> pos[i].first >> pos[i].second;
	}
	map<int, int> rows;
	for (int i=0; i<n; i++) {
		rows[pos[i].first]++;
	}
	map<int, int> cols;
	for (int i=0; i<n; i++) {
		cols[pos[i].second]++;
	}
	long long o = 0;
	for (int i=0; i<n; i++) {
		o += 1ll*(rows[pos[i].first]-1)*(cols[pos[i].second]-1);
	}
	cout << o << endl;
}