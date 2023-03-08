#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	int cost[n][n];
	vector< vector<int> > output;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> cost[i][j];
			if (cost[i][j] > -1) {
				output.push_back({i, j, cost[i][j]});
			}
		}
	}
	cout << output.size() << endl;
	for (auto i: output) {
		cout << i[0]+1 << " " << i[1]+1 << " " << i[2] << endl;
	}
}